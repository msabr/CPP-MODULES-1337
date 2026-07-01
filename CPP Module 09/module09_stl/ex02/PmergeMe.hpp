#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <string>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int argc, char **argv);

	private:
		// value, unique id (so duplicate values are handled unambiguously)
		typedef std::pair<long, long> Elem;

		std::vector<long> parseArgs(int argc, char **argv) const;

		std::vector<long> sortVector(const std::vector<long> &input) const;
		std::deque<long> sortDeque(const std::deque<long> &input) const;

		std::vector<Elem> mergeInsertVector(std::vector<Elem> elems) const;
		std::deque<Elem> mergeInsertDeque(std::deque<Elem> elems) const;

		// order (excluding index 0, already inserted) in which the "smaller"
		// elements must be inserted into the main chain, per Jacobsthal numbers
		std::vector<size_t> jacobsthalOrder(size_t n) const;
};

#endif
