#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int maxSize;
	public:
		Span(unsigned int n);
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		template <typename T>
		void addNumbers(T first, T last) {
			if (std::distance(first, last) + numbers.size() > maxSize)
				throw std::runtime_error("Exceeding maximum size");
			numbers.insert(numbers.end(), first, last);
		}
};

#endif