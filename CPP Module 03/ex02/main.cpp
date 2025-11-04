/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/11/04 00:54:04 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav1("Scav1");
	std::cout << "----------------------------------------" << std::endl;
	scav1.attack("Target1");
	scav1.guardGate();
	scav1.guardGate();
	scav1.guardGate();
	std::cout << "----------------------------------------" << std::endl;
	
	FragTrap frag1("Frag1");
	std::cout << "----------------------------------------" << std::endl;
	frag1.attack("Target1");
	frag1.highFivesGuys();
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}