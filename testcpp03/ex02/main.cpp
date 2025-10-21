#include "FragTrap.hpp"

int main()
{
    FragTrap f1("Frank");
    f1.attack("target");
    f1.highFivesGuys();

    FragTrap f2 = f1;
    f2.attack("another target");
    f2.highFivesGuys();

    return 0;
}
