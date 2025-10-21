#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int HitPoint;
        int EnergyPoints;
        int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
