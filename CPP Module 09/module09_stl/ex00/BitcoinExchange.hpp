#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInputFile(const std::string &filename);

	private:
		std::map<std::string, double> _database;

		bool isLeapYear(int year) const;
		bool isValidDate(const std::string &date) const;
		bool parseLine(const std::string &line, std::string &date, std::string &valueStr) const;
		double getRateForDate(const std::string &date) const;
};

#endif
