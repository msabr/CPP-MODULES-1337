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
		throw std::runtime_error("Error: could not open database file.");

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


void BitcoinExchange::printDatabase() const
{
	for (std::map<std::string, double>::const_iterator it = db.begin(); it != db.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}