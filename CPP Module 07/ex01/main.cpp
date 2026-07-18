/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:51:40 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:51:41 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void )
{
	int		array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print<int>);

	std::string	str_array[] = {"Hello", "World", "!"};
	iter(str_array, 3, print<std::string>);

	float	float_array[] = {1.1f, 2.2f, 3.3f};
	iter(float_array, 3, print<float>);

	return 0;
}
