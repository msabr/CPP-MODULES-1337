/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:58:58 by msabr             #+#    #+#             */
/*   Updated: 2025/11/04 00:43:35 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), guardMode(false) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n), guardMode(false) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
    this->guardMode = other.guardMode;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->guardMode = other.guardMode;
    }
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else if (hitPoints <= 0)
        std::cout << "ScavTrap " << name << " has no hit points left to attack!" << std::endl;
    else if (energyPoints <= 0)
        std::cout << "ScavTrap " << name << " has no energy points left to attack!" << std::endl;
}

void ScavTrap::guardGate() {
    guardMode = !guardMode;
    if (guardMode)
        std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << name << " has exited Gate Keeper mode." << std::endl;
}