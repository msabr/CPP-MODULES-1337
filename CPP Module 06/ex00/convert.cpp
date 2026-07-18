/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:50:14 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:50:15 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isInfi(std::string s)
{
	return (s == "-inf" || s == "+inf" || s == "-inff" || s == "+inff" || s == "nan" || s == "nanf");
}

static bool isChar(std::string s)
{
	return (s.size() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]));
}

static bool isInt(std::string s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') 
		i++;
	while (i < s.size())
	{
		if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	return true;
}

static bool isDouble(std::string s)
{
	bool hasDot = false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') 
		i++;
	while (i < s.size())
	{
		if (s[i] == '.') {
			if (hasDot) 
				return false; 
			hasDot = true; 
			if (i == 0)
				return false;
		}
		else if (!std::isdigit(s[i])) 
			return false;
		i++;
	}
	return hasDot;
}

static bool isFloat(std::string s)
{
	if (s[s.size()-1] != 'f')
		return false;
	return isDouble(s.substr(0, s.size() - 1));
}

static void printInf(std::string s)
{
	if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\n";
		std::cout << "double: -inf\n";
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\n";
		std::cout << "double: nan\n";
	}
}

static void printChar(double d)
{
	if (d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (d < 32)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
}

static void printInt(double d)
{
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
}

static void printFloat(double d)
{
	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<long>(d))
		std::cout << ".0";
	std::cout << "f\n";
}

static void printDouble(double d)
{
	std::cout << "double: " << d;
	if (d == static_cast<long>(d))
		std::cout << ".0";
	std::cout << "\n";
}

void ScalarConverter::convert(const std::string s)
{
	if (isInfi(s))
		return printInf(s);
	double d;
	if (isChar(s))
		d = static_cast<double>(s[0]);
	else if (isInt(s))
		d = static_cast<double>(std::atol(s.c_str()));
	else if (isFloat(s))
		d = static_cast<double>(std::atof(s.c_str()));
	else if (isDouble(s))
		d = std::atof(s.c_str());
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
