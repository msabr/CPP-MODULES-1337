/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:57:47 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 17:01:49 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool guardMode;
	public:
		ScavTrap(); // Default constructor
		ScavTrap(std::string n); // Parameterized constructor
		ScavTrap(const ScavTrap &other); // Copy constructor
		ScavTrap &operator=(const ScavTrap &other); // Copy assignment operator
		~ScavTrap(); // Destructor

		void attack(const std::string &target);
		void guardGate();
};

#endif