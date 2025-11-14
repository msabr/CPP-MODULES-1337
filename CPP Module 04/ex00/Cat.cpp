/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:21:17 by msabr             #+#    #+#             */
/*   Updated: 2025/11/07 01:30:54 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MYAW MYAWEE" << std::endl;
}
