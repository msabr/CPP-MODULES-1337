/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:17:34 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 16:55:54 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target 
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no hit points left to attack!" << std::endl;
	} else if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no energy points left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0) hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount 
			  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired by " << amount 
				  << " points! Current hit points: " << hitPoints << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no hit points left to be repaired!" << std::endl;
	} else if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no energy points left to be repaired!" << std::endl;
	}
}
