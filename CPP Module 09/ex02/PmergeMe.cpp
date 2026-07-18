/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:33 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:59:34 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}


PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	_vec = other._vec;
	_deq = other._deq;
	return *this;
}

PmergeMe::~PmergeMe(){}

static bool isNumber(const std::string& s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

static int toIntChecked(const std::string& s)
{
	long v = std::strtol(s.c_str(), 0, 10);
	if (v <= 0 || v > INT_MAX)
		throw std::runtime_error("Error");
	return static_cast<int>(v);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& input) const
{
	size_t n = input.size();
	if (n <= 1)
		return input;

	// size_t half = n / 2;
	// bool odd = (n % 2 != 0);

	std::vector< std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].second);

	std::vector<int> mainChain = fordJohnsonVector(winners);

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int loser = pairs[i].first;
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), loser);
		mainChain.insert(pos, loser);
	}

	if (input.size() % 2 != 0)
	{
		int straggler = input.back();
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}


std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& input) const
{
	if (input.size() <= 1)
		return input;

	std::deque< std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].second);

	std::deque<int> mainChain = fordJohnsonDeque(winners);

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int loser = pairs[i].first;
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), loser);
		mainChain.insert(pos, loser);
	}

	if (input.size() % 2 != 0)
	{
		int straggler = input.back();
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

void PmergeMe::loadData(int ac, char** av)
{
	if (ac < 2)
		throw std::runtime_error("Error");
	for (int i = 1; i < ac; ++i)
	{
		std::string s(av[i]);
		if (!isNumber(s))
			throw std::runtime_error("Error");
		int n = toIntChecked(s);
		_vec.push_back(n);
		_deq.push_back(n);
	}
}

void PmergeMe::process() 
{
	struct timeval start, end;
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	gettimeofday(&start, NULL);
	std::vector<int> sortedVec = fordJohnsonVector(_vec);
	gettimeofday(&end, NULL);
	double vtime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	std::deque<int> sortedDeq = fordJohnsonDeque(_deq);
	gettimeofday(&end, NULL);
	double dtime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	std::cout << "After:";
	for (size_t i = 0; i < sortedVec.size(); ++i)
		std::cout << " " << sortedVec[i];
	std::cout << std::endl;
	(void)sortedDeq;


	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vtime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << dtime << " us" << std::endl;
}