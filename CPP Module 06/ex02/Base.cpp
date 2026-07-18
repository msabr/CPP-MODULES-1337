/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:50:57 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:50:58 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int r = std::rand() % 3;
	if (r == 0) 
		return new A();
	if (r == 1) 
		return new B();
	return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p); 
		std::cout << "A\n"; 
		return; 
	} catch (...) {}
	try { 
		(void)dynamic_cast<B &>(p); 
		std::cout << "B\n"; 
		return; 
	} catch (...) {}
	try { 
		(void)dynamic_cast<C &>(p); 
		std::cout << "C\n"; 
		return; 
	} catch (...) {}
	std::cout << "Unknown\n";
}
