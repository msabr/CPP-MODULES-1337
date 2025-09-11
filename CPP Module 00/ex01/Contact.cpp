/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:36:13 by msabr             #+#    #+#             */
/*   Updated: 2025/09/08 23:52:04 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool isPrintable(std::string& str) 
{
	int i = 0;

	while (str[i]) 
	{
		if (!isprint(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void Contact::setInfo() {
	do {
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, firstName))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (firstName.empty() || !isPrintable(firstName));
	do {
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, lastName))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (lastName.empty() || !isPrintable(lastName));
	do {
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, nickname))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (nickname.empty() || !isPrintable(nickname));
	do {
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, phoneNumber))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (phoneNumber.empty() || !isPrintable(phoneNumber) || !isNumber(phoneNumber));
	do {
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, darkestSecret))
		{
			std::cout << "Error reading input. Goodbay" << std::endl;
			exit(1);
		}
	} while (darkestSecret.empty() || !isPrintable(darkestSecret));
}

static std::string addDot(std::string s) {
	std::string res;

	for (int i = 0; i < MAX_CASES - 1; i++)
		res += s[i];
	res += '.';
	return (res);
}

static std::string format(std::string s) {
	if (s.length() > MAX_CASES)
		return (addDot(s));
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
