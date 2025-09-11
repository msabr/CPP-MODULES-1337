/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 02:04:35 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 03:34:37 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* zombieP1 = newZombie("Harry");
	zombieP1->announce();
	delete zombieP1;

	randomChump("Ron");

	return 0;
}