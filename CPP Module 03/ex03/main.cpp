/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 17:33:26 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt1("DiamondOne");
	dt1.whoAmI();
	dt1.attack("Target1");
	dt1.takeDamage(30);
	dt1.beRepaired(20);

	std::cout << "------------------------" << std::endl;

	DiamondTrap dt2 = dt1; // Copy constructor
	dt2.whoAmI();
	dt2.attack("Target2");
	dt2.takeDamage(50);
	dt2.beRepaired(40);

	std::cout << "------------------------" << std::endl;

	DiamondTrap dt3;
	dt3 = dt1; // Copy assignment operator
	dt3.whoAmI();
	dt3.attack("Target3");
	dt3.takeDamage(70);
	dt3.beRepaired(60);
	return 0;
}
