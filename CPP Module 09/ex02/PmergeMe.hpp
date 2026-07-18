/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:53:06 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:53:07 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	std::vector<int> fordJohnsonVector(const std::vector<int>& input) const;
	std::deque<int> fordJohnsonDeque(const std::deque<int>& input) const;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void loadData(int ac, char** av);
	void process();
};

#endif