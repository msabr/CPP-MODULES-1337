/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:36 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 19:51:10 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : db(other.db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		db = other.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static void validateFilename(const std::string &filename)
{
	if (filename.length() < 5
		|| filename.compare(filename.length() - 4, 4, ".csv") != 0)
		throw std::runtime_error("File must have *.csv extension");
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
	validateFilename(filename);
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);
		double rate = std::stod(rateStr);
		db[date] = rate;
	}
	file.close();
}

//=====================================================================================

static bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(date d)
{
	if (d.month < 1 || d.month > 12)
		return false;
	if (d.day < 1)
		return false;
	int maxDaysinMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (d.month == 2 && isLeapYear(d.year))
		maxDaysinMonth[1] = 29;
	if (d.day > maxDaysinMonth[d.month - 1])
		return false;
	return true;
}

static bool isValidFormat(std::string line)
{
	size_t	i;

	if (line.size() != 10)
		return false;
	for (i = 0; i < line.size(); ++i)
	{
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				return false;
		}
		else if (!std::isdigit(line[i]))
			return false;
	}
	return true;
}

static bool isValidDatestr(const std::string &line)
{
	if (!isValidFormat(line))
		return false;
	date d;
	d.year = std::atoi(line.substr(0, 4).c_str());
	d.month = std::atoi(line.substr(5, 2).c_str());
	d.day = std::atoi(line.substr(8, 2).c_str());
	if (!isValidDate(d))
		return false;
	return true;
}

static int count_char(std::string &str, char c)
{
	int count = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

static std::string ft_strtrim(std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(start, end - start + 1);
}

static bool splitpipe(std::string &line, std::string &datestr, std::string &valueStr)
{
	size_t pipePos = line.find('|');
	if (count_char(line, '|') != 1)
		return false;
	if (pipePos == std::string::npos)
		return false;
	datestr = ft_strtrim(line.substr(0, pipePos));
	valueStr = ft_strtrim(line.substr(pipePos + 1));
	if (datestr.empty() || valueStr.empty())
		return false;
	return true;
}

void BitcoinExchange::Exchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::string datestr;
	std::string valueStr;
	std::getline(file, line);
	if (!splitpipe(line, datestr, valueStr) || datestr != "date" || valueStr != "value")
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (!splitpipe(line, datestr, valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;	continue;
		}
		if (!isValidDatestr(datestr))
		{
			std::cout << "Error: bad input => " << datestr << std::endl;	continue;
		}

		char *endptr;
		double value = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;	continue;
		}
		else if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;	continue;
		}
		else if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;	continue;
		}

		try
		{
			double rate = getValueFromDB(datestr);
			double result = value * rate;
			std::cout << datestr << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}

double BitcoinExchange::getValueFromDB(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = db.lower_bound(date);

	if (it != db.end() && it->first == date)
		return it->second;

	if (it == db.begin())
		throw std::runtime_error("Error: no date in database prior to " + date);

	--it;
	return it->second;
}