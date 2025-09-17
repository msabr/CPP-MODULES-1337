/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:34:07 by msabr             #+#    #+#             */
/*   Updated: 2025/09/17 17:43:36 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
	return type;
}

void Weapon::setType(std::string t) {
	type = t;
}

Weapon::Weapon(std::string t): type(t) {
}

Weapon::~Weapon(void) {
	std::cout << "Weapon destroyed" << std::endl;
}
