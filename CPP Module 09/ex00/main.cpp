/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:41 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:52:42 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange bitcoine;
	try
	{
		bitcoine.loadDatabase("data.csv");
		bitcoine.Exchange(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}