#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

static bool isValidOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::evaluate(const std::string &expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (std::isdigit(c))
			_stack.push(c - '0');
		else if (isValidOperator(c))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Invalid RPN expression");
			long b = _stack.top();   _stack.pop();
			long a = _stack.top();   _stack.pop();
			switch (c)
			{
				case '+':
					_stack.push(a + b);
					break;
				case '-':
					_stack.push(a - b);
					break;
				case '*':
					_stack.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Division by Zero");
					_stack.push(a / b);
					break;
			}
		}
		else if (!std::isspace(c))
		{
			throw std::runtime_error("Invalid character expression");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid RPN expression");
	return _stack.top();
}