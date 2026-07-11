#include "BitcoinExchange.hpp"

static std::string ft_strtrim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(start, end - start + 1);
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidFormat(std::string line)
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

bool isValidDate(date d)
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

bool isValidLine(const std::string &line)
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
int	count_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = db.lower_bound(date);

	if (it != db.end() && it->first == date)
		return it->second;

	if (it == db.begin())
		throw std::runtime_error("Error: no date in database prior to " + date);

	--it;
	return it->second;
}

static bool splitpipe(std::string &line, std::string &date, std::string &valueStr)
{
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
		return false;
	date = ft_strtrim(line.substr(0, pipePos));
	valueStr = ft_strtrim(line.substr(pipePos + 1));
	if (date.empty() || valueStr.empty())
		return false;
	return true;
}

void BitcoinExchange::Exchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string datestr;
		std::string valueStr;
		if (!splitpipe(line, datestr, valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidLine(datestr))
		{
			std::cout << "Error: bad input => " << datestr << std::endl;
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
			double rate = getRateForDate(datestr);
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