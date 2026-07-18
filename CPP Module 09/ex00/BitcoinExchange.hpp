/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:38 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:52:39 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

struct date 
{
	int year;
	int month;
	int day;
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		double getValueFromDB(const std::string &date) const;
		void loadDatabase(const std::string &filename);
		void Exchange(const std::string &filename);
		~BitcoinExchange();
};

#endif