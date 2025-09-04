/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:36:13 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 11:48:51 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setInfo() {
	do {
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, firstName))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (firstName.empty());
	do {
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, lastName))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (lastName.empty());
	do {
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, nickname))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (nickname.empty());
	do {
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, phoneNumber))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (phoneNumber.empty());
	do {
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, darkestSecret))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (darkestSecret.empty());
}


static std::string format(std::string s) {
	if (s.length() > MAX_CASES)
		return (s.substr(0, 9) + ".");
	return (s);
}

void Contact::displayRow(int row) const {
	std::cout << std::setw(MAX_CASES) << row << "|"
			  << std::setw(MAX_CASES) << format(firstName) << "|"
			  << std::setw(MAX_CASES) << format(lastName) << "|"
			  << std::setw(MAX_CASES) << format(nickname) << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl
			  << "Last Name: " << lastName << std::endl
			  << "Nickname: " << nickname << std::endl
			  << "Phone Number: " << phoneNumber << std::endl
			  << "Darkest Secret: " << darkestSecret << std::endl;
}

