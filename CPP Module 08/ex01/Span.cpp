#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize)
		throw std::runtime_error("Span is full");
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}

