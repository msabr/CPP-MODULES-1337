#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("Clap");
    ct.attack("Target");
    ct.takeDamage(5);
    ct.beRepaired(3);
    return 0;
}