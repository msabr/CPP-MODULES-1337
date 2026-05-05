#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
	std::vector<int> numbers;
	unsigned int maxSize;
public:
	Span(unsigned int n);
	void addNumber(int number);
	template <typename InputIt>
	void addNumbers(InputIt first, InputIt last) {
		if (std::distance(first, last) + numbers.size() > maxSize)
			throw std::runtime_error("Exceeding maximum size");
		numbers.insert(numbers.end(), first, last);
	}
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

};

#endif