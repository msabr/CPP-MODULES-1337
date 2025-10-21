/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/10/15 16:58:09 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1("Clap");
	ClapTrap clap2 = clap1;
	ClapTrap clap3;
	clap3 = clap1;

	std::cout << "-----------------------------------" << std::endl;
	clap1.attack("Target1");
	clap1.takeDamage(-1);
	clap1.beRepaired(3);
	std::cout << "-----------------------------------" << std::endl;
	clap2.attack("Target2");
	clap2.takeDamage(15);
	clap2.beRepaired(10);
	std::cout << "-----------------------------------" << std::endl;
	clap3.attack("Target3");
	clap3.takeDamage(8);
	clap3.beRepaired(5);
	std::cout << "-----------------------------------" << std::endl;

	return 0;
}
