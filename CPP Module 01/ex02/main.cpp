/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 02:04:35 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 03:56:28 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout	<< "The memory address of the string variable: " 
				<< &var << std::endl;
	std::cout	<< "The memory address held by stringPTR: "
				<< stringPTR << std::endl;
	std::cout	<< "The memory address held by stringREF: "
				<< &stringREF << std::endl;

	std::cout	<< "The value of the string variable: " 
				<< var << std::endl;
	std::cout	<< "The value pointed to by stringPTR: "
				<< *stringPTR << std::endl;
	std::cout	<< "The value pointed to by stringREF: "
				<< stringREF << std::endl;
	return 0;
}
