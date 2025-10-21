#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    this->HitPoint = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Default Constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name)
{
    this->HitPoint = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Constructor for " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap Copy Constructor called for " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap Assignment operator called for " << this->name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->EnergyPoints > 0 && this->HitPoint > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else if (this->EnergyPoints == 0)
        std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because it has no energy points left." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because it is dead." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
