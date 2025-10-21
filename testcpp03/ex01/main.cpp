#include "ScavTrap.hpp"

int main()
{
    ScavTrap s1("Bob");
    s1.attack("X");
    s1.guardGate();

    ScavTrap s2 = s1;
    s2.attack("Y");

    return 0;
}