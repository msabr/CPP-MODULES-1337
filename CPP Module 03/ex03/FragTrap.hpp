/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:26:16 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 17:40:36 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    protected:
        FragTrap(); // Default constructor
        FragTrap(std::string n); // Parameterized constructor
        FragTrap(const FragTrap &other); // Copy constructor
        FragTrap &operator=(const FragTrap &other); // Copy assignment operator
        ~FragTrap(); // Destructor

        void highFivesGuys();
};

#endif