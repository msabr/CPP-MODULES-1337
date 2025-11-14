/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:20:14 by msabr             #+#    #+#             */
/*   Updated: 2025/11/07 01:50:32 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "HAW HAW HAWHAW" << std::endl;
}
