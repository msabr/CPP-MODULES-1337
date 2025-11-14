/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:17:59 by msabr             #+#    #+#             */
/*   Updated: 2025/11/07 01:26:14 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal Copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "sound of Animal" << std::endl;
}

