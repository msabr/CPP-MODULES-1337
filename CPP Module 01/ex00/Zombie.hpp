/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:32:45 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 03:29:45 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		void announce(void);
		Zombie(void);
		~Zombie(void);
		void setName(std::string name);
		std::string getName(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif