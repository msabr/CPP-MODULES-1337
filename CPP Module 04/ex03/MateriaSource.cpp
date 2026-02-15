/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:07:03 by msabr             #+#    #+#             */
/*   Updated: 2025/12/17 17:25:48 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        materia[i] = other.materia[i] ? other.materia[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materia[i];
            materia[i] = other.materia[i] ? other.materia[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!materia[i])
        {
            materia[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return NULL;
}


