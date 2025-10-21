#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap("Default")
{
    std::cout << "FragTrap Default Constructor called for " << this->name << std::endl;
    this->HitPoint = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap Constructor for " << this->name << " called" << std::endl;
    this->HitPoint = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor called for " << this->name << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Assignment operator called for " << this->name << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called for " << this->name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->EnergyPoints > 0 && this->HitPoint > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else if (this->EnergyPoints == 0)
        std::cout << "FragTrap " << this->name << " is not able to attack " << target << ", because it has no energy points left." << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is not able to attack " << target << ", because it is dead." << std::endl;
}

void FragTrap::highFivesGuys()
{
    if (this->HitPoint <= 0)
    {
        std::cout << "FragTrap " << this->name << " can't high-five, it's dead." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
