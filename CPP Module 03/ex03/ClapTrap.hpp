/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:17:16 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 18:09:28 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    
    public:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
        ClapTrap(); // Default constructor
        ClapTrap(std::string n); // Parameterized constructor
        ClapTrap(const ClapTrap &other); // Copy constructor
        ClapTrap &operator=(const ClapTrap &other); // Copy assignment operator
        ~ClapTrap(); // Destructor

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif