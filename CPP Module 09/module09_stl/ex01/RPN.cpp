#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const
{
	if (token.empty())
		return false;

	size_t i = 0;
	if (token[0] == '-' && token.size() > 1)
		i = 1;

	if (i >= token.size())
		return false;

	for (; i < token.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			return false;
	}
	return true;
}

int RPN::evaluate(const std::string &expression) const
{
	std::stack<long> values;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			long value = std::atol(token.c_str());
			if (value > 9 || value < -9)
				throw std::runtime_error("Error");
			values.push(value);
		}
		else if (isOperator(token))
		{
			if (values.size() < 2)
				throw std::runtime_error("Error");

			long b = values.top();
			values.pop();
			long a = values.top();
			values.pop();

			long result = 0;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else // "/"
			{
				if (b == 0)
					throw std::runtime_error("Error");
				result = a / b;
			}

			if (result > INT_MAX || result < INT_MIN)
				throw std::runtime_error("Error");

			values.push(result);
		}
		else
			throw std::runtime_error("Error");
	}

	if (values.size() != 1)
		throw std::runtime_error("Error");

	return static_cast<int>(values.top());
}
