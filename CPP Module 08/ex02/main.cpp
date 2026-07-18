/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:23 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:52:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "========== Basic Test ==========\n";

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	std::cout << "\nElements:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n========== Copy Constructor ==========\n";

	MutantStack<int> copy(mstack);

	it = copy.begin();
	ite = copy.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n========== Assignment Operator ==========\n";

	MutantStack<int> assign;

	assign.push(100);
	assign.push(200);

	assign = mstack;

	it = assign.begin();
	ite = assign.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n========== Empty Stack ==========\n";

	MutantStack<int> empty;

	std::cout << "empty(): " << empty.empty() << std::endl;
	std::cout << "size(): " << empty.size() << std::endl;

	return (0);
}