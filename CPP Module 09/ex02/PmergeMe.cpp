/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:59:33 by msabr             #+#    #+#             */
/*   Updated: 2026/07/19 15:05:17 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	_vec = other._vec;
	_deq = other._deq;
	return *this;
}

PmergeMe::~PmergeMe(){}

//=====================================================================================

static bool isNumber(std::string& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[0] == '+')
		i++;
	for (; i < s.size(); ++i)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

static int toIntChecked(std::string& s)
{
	long v = std::strtol(s.c_str(), 0, 10);
	if (v > INT_MAX)
		throw std::runtime_error("Error");
	return static_cast<int>(v);
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

//=====================================================================================

std::vector<int> Jacobsthal(int n) {
	std::vector<int> order;
	if (n <= 0) 
		return order;

	std::vector<int> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() < n) {
		int m = jac.size();
		jac.push_back(jac[m - 1] + 2 * jac[m - 2]);
	}

	order.push_back(0);

	for (size_t k = 2; k < jac.size(); ++k) {
		for (int i = jac[k] - 1; i >= jac[k - 1]; --i) {
			if (i < n) order.push_back(i);
		}
	}

	return order;
}

static void MatchOrderDeque(std::vector<std::pair<int, int> > &pairs, std::deque<int> &result)
{
	std::vector<std::pair<int, int> > sorted(pairs.size());
	std::vector<bool> used(pairs.size(), false);

	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == result[i] && !used[j])
			{
				sorted[i] = pairs[j];
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted;
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> input)
{
	if (input.size() <= 1)
		return input;

	bool isOdd = input.size() % 2;
	int straggler = input.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);

	std::deque<int> result = fordJohnsonDeque(winners);

	MatchOrderDeque(pairs, result);
	std::vector<int> order = Jacobsthal(pairs.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i];
		std::deque<int>::iterator upper = std::find(result.begin(), result.end(), pairs[idx].second);
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), upper, pairs[idx].first);
		result.insert(pos, pairs[idx].first);
	}

	if (isOdd)
	{
		std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}

	return result;
}

//=====================================================================================


static void MatchOrderVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &result)
{
	std::vector<std::pair<int, int> > sorted(pairs.size());
	std::vector<bool> used(pairs.size(), false);

	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == result[i] && !used[j])
			{
				sorted[i] = pairs[j];
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted;
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> input)
{
	if (input.size() <= 1)
		return input;

	bool isOdd = input.size() % 2;
	int straggler = input.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	std::vector<int> result = fordJohnsonVector(winners);

	MatchOrderVector(pairs, result);
	std::vector<int> order = Jacobsthal(pairs.size());
	
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i];
		std::vector<int>::iterator upper = std::find(result.begin(), result.end(), pairs[idx].second);
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), upper, pairs[idx].first);
		result.insert(pos, pairs[idx].first);
	}

	if (isOdd)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}
	return result;
}

static double getTime(struct timeval start, struct timeval end)
{
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
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
	double vtime = getTime(start, end);

	gettimeofday(&start, NULL);
	std::deque<int> sortedDeq = fordJohnsonDeque(_deq);
	gettimeofday(&end, NULL);
	double dtime = getTime(start, end);

	std::cout << "After:";
	for (size_t i = 0; i < sortedVec.size(); ++i)
		std::cout << " " << sortedVec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vtime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << dtime << " us" << std::endl;
}