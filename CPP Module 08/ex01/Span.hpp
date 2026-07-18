/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:20 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:52:21 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		template <typename T>
		void addNumbers(T first, T last) {
			if (std::distance(first, last) + numbers.size() > maxSize)
				throw std::runtime_error("Exceeding maximum size");
			for (T it = first; it != last; ++it) {
				numbers.push_back(*it);
			}
		}
		~Span();
};

#endif