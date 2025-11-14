/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:33:49 by msabr             #+#    #+#             */
/*   Updated: 2025/11/07 01:36:55 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	std::string result = "";
	if (index >= 0 && index < 100)
	{
		result = this->ideas[index];
	}
	return result;
}
