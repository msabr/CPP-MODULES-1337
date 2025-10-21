#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Deafult"), HitPoint(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string _name) : name(_name), HitPoint(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Constructor for the name " << name << " called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    this->name = other.name;
    this->HitPoint = other.HitPoint;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return *this;
}
ClapTrap::~ClapTrap() { std::cout << "ClapTrap Deconstructor for " << name << " called" << std::endl; }
void ClapTrap::attack(const std::string &target)
{
    if (this->EnergyPoints > 0 && this->HitPoint > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else if (this->EnergyPoints == 0)
        std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has is Dead." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoint > amount)
        this->HitPoint -= amount;
    else if (this->HitPoint > 0)
        this->HitPoint = 0;
    else
    {
        std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoints > 0 && this->HitPoint > 0 && this->HitPoint + amount <= 10)
    {
        this->HitPoint += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points." << std::endl;
        this->EnergyPoints--;
    }
    else if (this->EnergyPoints == 0)
        std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
    else if (this->HitPoint == 0)
        std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he is Dead." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;
}