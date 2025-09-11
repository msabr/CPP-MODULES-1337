/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:52:08 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 03:28:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie();
    if (zombie == NULL) {
        std::cerr << "Memory allocation failed" << std::endl;
        return NULL;
    }
    zombie->setName(name);
    return zombie;
}