/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:30 by msabr             #+#    #+#             */
/*   Updated: 2025/11/03 23:51:21 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clap1");
	ClapTrap clap2("Clap2");

	std::cout << "----------------------------------------" << std::endl;
	clap1.attack("Clap2");
	clap1.takeDamage(1);
	clap1.beRepaired(2);
	std::cout << "----------------------------------------" << std::endl;
	clap2.attack("Clap1");
	clap2.takeDamage(10);
	clap2.beRepaired(5);
	clap2.attack("Clap1");
	std::cout << "----------------------------------------" << std::endl;

	return (0);
}