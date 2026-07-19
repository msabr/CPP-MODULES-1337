/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:53:06 by msabr             #+#    #+#             */
/*   Updated: 2026/07/19 14:23:57 by msabr            ###   ########.fr       */
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

	std::vector<int> fordJohnsonVector(std::vector<int> input);
	std::deque<int> fordJohnsonDeque(std::deque<int> input);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void loadData(int ac, char** av);
	void process();
};

#endif