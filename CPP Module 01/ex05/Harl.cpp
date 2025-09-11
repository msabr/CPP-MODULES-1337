/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:08:47 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 08:07:51 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
}

void Harl::complain(std::string level){
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++){
		if (levels[i] == level){
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[ UNKNOWN LEVEL ]" << std::endl;
}