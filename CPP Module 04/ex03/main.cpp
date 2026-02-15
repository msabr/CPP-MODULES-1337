/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:38:20 by msabr             #+#    #+#             */
/*   Updated: 2025/12/28 16:43:03 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void    f()
{
    system("leaks Animal");
}

int main()
{
    atexit(f);
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("cure");
    for (int i = 0; i < 4; i++)
    {
        
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->unequip(i);
    }
    // array fih 4 kanstori fich chi 7aja mli kandirha funequip


    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");

    // me->use(0, *bob);
    // me->use(1, *bob);

    // delete bob;
    delete me;
    delete src;

    return 0;

}


