#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

void Span::addNumber(int number) {
	if (numbers.size() + 1 > maxSize)
		throw std::runtime_error("No space left");
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("No span can be found");

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	
	unsigned int minSpan = 2147483647;
	for (size_t i = 0; i < sortedNumbers.size(); i++) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("No span can be found");
	unsigned int min = *std::min_element(numbers.begin(), numbers.end());
	unsigned int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}
