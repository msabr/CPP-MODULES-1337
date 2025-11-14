/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:38:20 by msabr             #+#    #+#             */
/*   Updated: 2025/11/07 01:49:43 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void f()
{
	system("leaks Animal");
}
int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	atexit(f);
	delete j;//should not create a leak
	delete i;

	return 0;
}
	


