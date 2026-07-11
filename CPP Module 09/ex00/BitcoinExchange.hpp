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
        ~BitcoinExchange();
        void loadDatabase(const std::string &filename);
        void Exchange(const std::string &filename);
        void printDatabase() const;
        double getRateForDate(const std::string &date) const;

    
};

#endif