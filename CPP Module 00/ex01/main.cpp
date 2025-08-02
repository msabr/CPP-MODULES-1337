/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:36:00 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 04:19:51 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook pb;
	std::string cmd;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd)) {
			std::cout << "\nError reading input. Goodbye." << std::endl;
			return (1);
		}
		if (cmd == "ADD")
			pb.addContact();
		else if (cmd == "SEARCH")
			pb.searchContact();
		else if (cmd == "EXIT")
		{
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		}
	}
	return (0);
}
