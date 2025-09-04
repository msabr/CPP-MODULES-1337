/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:36:07 by msabr             #+#    #+#             */
/*   Updated: 2025/08/04 04:19:38 by msabr            ###   ########.fr       */
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

void PhoneBook::searchContact() const {
	printHeader();
	if (total == 0) {
		std::cout << std::setw(30) << "PhoneBook is empty.\n" << std::endl;
		return;
	}
	
	for (int i = 0; i < total; i++){
		contacts[i].displayRow(i);	
	}
	std::string input;
    int index;
	do{
		std::cout << "Enter index (0 to " << total - 1 << "): ";
		if (!std::getline(std::cin, input)) {
			return;
		}
	} while (input.empty());
	if (!isdigit(input[0]) && input[0] == '+' && input[0] == '-') {
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index >= total) {
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}
	contacts[index].displayFull();
	std::cout << std::endl;
}
