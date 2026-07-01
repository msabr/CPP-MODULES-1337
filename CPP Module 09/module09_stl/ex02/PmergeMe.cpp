#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

static bool compareElem(const std::pair<long, long> &a, const std::pair<long, long> &b)
{
	return a.first < b.first;
}

/*
** Jacobsthal numbers: J(0)=0, J(1)=1, J(k)=J(k-1)+2*J(k-2)
** => 0, 1, 1, 3, 5, 11, 21, 43, 85, ...
** The "losers" (smaller elements) are inserted into the main chain in
** descending order within each [J(k-1)+1, J(k)] group, which minimises
** the number of comparisons required by the binary insertion.
*/
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n) const
{
	std::vector<size_t> order;
	if (n <= 1)
		return order;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::vector<bool> inserted(n, false);
	inserted[0] = true; // index 0 is always inserted before this ordering is used

	for (size_t k = 2; k < jacob.size(); ++k)
	{
		size_t hi = jacob[k];
		if (hi >= n)
			hi = n - 1;
		size_t lo = jacob[k - 1];

		for (size_t i = hi; i > lo; --i)
		{
			if (i < n && !inserted[i])
			{
				order.push_back(i);
				inserted[i] = true;
			}
		}
	}

	for (size_t i = 1; i < n; ++i)
	{
		if (!inserted[i])
		{
			order.push_back(i);
			inserted[i] = true;
		}
	}

	return order;
}

std::vector<PmergeMe::Elem> PmergeMe::mergeInsertVector(std::vector<Elem> elems) const
{
	if (elems.size() <= 1)
		return elems;

	bool hasStraggler = (elems.size() % 2 != 0);
	Elem straggler(0, 0);
	if (hasStraggler)
	{
		straggler = elems.back();
		elems.pop_back();
	}

	std::vector<Elem> larger;
	std::vector<Elem> smaller;
	for (size_t i = 0; i < elems.size(); i += 2)
	{
		Elem a = elems[i];
		Elem b = elems[i + 1];
		if (a.first < b.first)
			std::swap(a, b);
		larger.push_back(a);
		smaller.push_back(b);
	}

	std::vector<Elem> sortedLarger = mergeInsertVector(larger);

	// realign each "smaller" element with its partner's new position, by id
	std::vector<Elem> sortedSmaller(sortedLarger.size());
	for (size_t i = 0; i < larger.size(); ++i)
	{
		long id = larger[i].second;
		for (size_t j = 0; j < sortedLarger.size(); ++j)
		{
			if (sortedLarger[j].second == id)
			{
				sortedSmaller[j] = smaller[i];
				break;
			}
		}
	}

	std::vector<Elem> mainChain = sortedLarger;

	if (!sortedSmaller.empty())
		mainChain.insert(mainChain.begin(), sortedSmaller[0]);

	std::vector<size_t> order = jacobsthalOrder(sortedSmaller.size());
	for (size_t k = 0; k < order.size(); ++k)
	{
		Elem &val = sortedSmaller[order[k]];
		std::vector<Elem>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val, compareElem);
		mainChain.insert(pos, val);
	}

	if (hasStraggler)
	{
		std::vector<Elem>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler, compareElem);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

std::deque<PmergeMe::Elem> PmergeMe::mergeInsertDeque(std::deque<Elem> elems) const
{
	if (elems.size() <= 1)
		return elems;

	bool hasStraggler = (elems.size() % 2 != 0);
	Elem straggler(0, 0);
	if (hasStraggler)
	{
		straggler = elems.back();
		elems.pop_back();
	}

	std::deque<Elem> larger;
	std::deque<Elem> smaller;
	for (size_t i = 0; i < elems.size(); i += 2)
	{
		Elem a = elems[i];
		Elem b = elems[i + 1];
		if (a.first < b.first)
			std::swap(a, b);
		larger.push_back(a);
		smaller.push_back(b);
	}

	std::deque<Elem> sortedLarger = mergeInsertDeque(larger);

	std::deque<Elem> sortedSmaller(sortedLarger.size());
	for (size_t i = 0; i < larger.size(); ++i)
	{
		long id = larger[i].second;
		for (size_t j = 0; j < sortedLarger.size(); ++j)
		{
			if (sortedLarger[j].second == id)
			{
				sortedSmaller[j] = smaller[i];
				break;
			}
		}
	}

	std::deque<Elem> mainChain = sortedLarger;

	if (!sortedSmaller.empty())
		mainChain.push_front(sortedSmaller[0]);

	std::vector<size_t> order = jacobsthalOrder(sortedSmaller.size());
	for (size_t k = 0; k < order.size(); ++k)
	{
		Elem &val = sortedSmaller[order[k]];
		std::deque<Elem>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val, compareElem);
		mainChain.insert(pos, val);
	}

	if (hasStraggler)
	{
		std::deque<Elem>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler, compareElem);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

std::vector<long> PmergeMe::sortVector(const std::vector<long> &input) const
{
	std::vector<Elem> elems;
	for (size_t i = 0; i < input.size(); ++i)
		elems.push_back(Elem(input[i], static_cast<long>(i)));

	std::vector<Elem> sorted = mergeInsertVector(elems);

	std::vector<long> result;
	for (size_t i = 0; i < sorted.size(); ++i)
		result.push_back(sorted[i].first);
	return result;
}

std::deque<long> PmergeMe::sortDeque(const std::deque<long> &input) const
{
	std::deque<Elem> elems;
	for (size_t i = 0; i < input.size(); ++i)
		elems.push_back(Elem(input[i], static_cast<long>(i)));

	std::deque<Elem> sorted = mergeInsertDeque(elems);

	std::deque<long> result;
	for (size_t i = 0; i < sorted.size(); ++i)
		result.push_back(sorted[i].first);
	return result;
}

std::vector<long> PmergeMe::parseArgs(int argc, char **argv) const
{
	std::vector<long> result;

	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error");

		size_t j = 0;
		if (token[0] == '+')
			j = 1;
		if (j >= token.size())
			throw std::runtime_error("Error");

		for (size_t k = j; k < token.size(); ++k)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[k])))
				throw std::runtime_error("Error");
		}

		char *endptr;
		long value = std::strtol(token.c_str(), &endptr, 10);
		if (*endptr != '\0' || value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		result.push_back(value);
	}

	if (result.empty())
		throw std::runtime_error("Error");

	return result;
}

void PmergeMe::run(int argc, char **argv)
{
	std::vector<long> values = parseArgs(argc, argv);

	std::cout << "Before: ";
	for (size_t i = 0; i < values.size(); ++i)
		std::cout << values[i] << (i + 1 < values.size() ? " " : "");
	std::cout << std::endl;

	std::vector<long> vecInput(values.begin(), values.end());
	std::deque<long> deqInput(values.begin(), values.end());

	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	std::vector<long> sortedVec = sortVector(vecInput);
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	std::deque<long> sortedDeq = sortDeque(deqInput);
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

	std::cout << "After: ";
	for (size_t i = 0; i < sortedVec.size(); ++i)
		std::cout << sortedVec[i] << (i + 1 < sortedVec.size() ? " " : "");
	std::cout << std::endl;

	std::cout << "Time to process a range of " << values.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << values.size()
		<< " elements with std::deque : " << deqTime << " us" << std::endl;

	(void)sortedDeq;
}
