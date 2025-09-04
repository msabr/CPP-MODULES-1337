/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:36:07 by msabr             #+#    #+#             */
/*   Updated: 2025/09/04 15:48:11 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : total(0), next(0) {}

void PhoneBook::addContact() {
	contacts[next].setInfo();
	next = (next + 1) % MAX_CONTACTS;
	if (total < MAX_CONTACTS)
		total++;
}

static void printHeader() {
	std::cout << std::left << std::setw(MAX_CASES) << "Index" << "|"
			  << std::left << std::setw(MAX_CASES) << "First Name" << "|"
			  << std::left << std::setw(MAX_CASES) << "Last Name" << "|"
			  << std::left << std::setw(MAX_CASES) << "Nickname" << std::endl;
	std::cout << std::right << std::string(44, '-') << std::endl;
}

bool isNumber(const std::string& str) {
	int i = 0;
	while (str[i]) {
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int ft_stoi(const std::string& str)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void PhoneBook::searchContact() const 
{

	printHeader();
	if (total == 0) {
		std::cout << std::setw(30) << "PhoneBook is empty.\n" << std::endl;
		return;
	}
	for (int i = 0; i < total; i++){
		contacts[i].displayRow(i);	
	}
	
	std::string input;
	do{
		std::cout << "Enter index (0 to " << total - 1 << "): ";
		if (!std::getline(std::cin, input)) {
			return;
		}
	} while (input.empty());
	if (!isNumber(input)) {
		std::cout << "Invalid input. Not a number." << std::endl;
		return;
	}
	
    int index;
	index = ft_stoi(input);
	if (index < 0 || index >= total) {
		std::cout << "Invalid index. Out of range." << std::endl;
		return;
	}
	contacts[index].displayFull();
	std::cout << std::endl;
}
