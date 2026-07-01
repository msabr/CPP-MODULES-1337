#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

static std::string trim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(start, end - start + 1);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	if (day > maxDay)
		return false;

	return true;
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &valueStr) const
{
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
		return false;
	date = trim(line.substr(0, pipePos));
	valueStr = trim(line.substr(pipePos + 1));
	if (date.empty() || valueStr.empty())
		return false;
	return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(date))
			continue;

		char *endptr;
		double rate = std::strtod(rateStr.c_str(), &endptr);
		if (*endptr != '\0')
			continue;

		_database[date] = rate;
	}
	file.close();

	if (_database.empty())
		throw std::runtime_error("Error: database is empty or invalid.");
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it->second;

	if (it == _database.begin())
		throw std::runtime_error("Error: no date in database prior to " + date);

	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header line "date | value"

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string date, valueStr;
		if (!parseLine(line, date, valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *endptr;
		double value = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0')
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = getRateForDate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}
