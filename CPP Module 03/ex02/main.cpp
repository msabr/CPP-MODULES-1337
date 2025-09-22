/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 17:27:55 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	ClapTrap clap("Clap");
	FragTrap frag("Frag");

	std::cout << "-----------------------------------" << std::endl;
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << "-----------------------------------" << std::endl;
	frag.attack("Target2");
	frag.takeDamage(15);
	frag.beRepaired(10);
	frag.highFivesGuys();
	std::cout << "-----------------------------------" << std::endl;
	return 0;
}
