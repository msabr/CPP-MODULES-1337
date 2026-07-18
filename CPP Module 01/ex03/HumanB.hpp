/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:46:47 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:46:48 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMMANB_HPP
#define HUMMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void setWeapon(Weapon& weapon);
		void attack(void);
};

#endif