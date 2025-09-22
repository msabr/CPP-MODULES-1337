/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 17:04:05 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	std::cout << "-----------------------------------" << std::endl;
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << "-----------------------------------" << std::endl;
	scav.attack("Target2");
	scav.takeDamage(15);
	scav.beRepaired(10);
	scav.guardGate();
	std::cout << "-----------------------------------" << std::endl;

	return 0;
}
