/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:51:38 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:51:39 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F fun)
{
	for (size_t i = 0; i < length; i++)
		fun(array[i]);
}

template <typename T>
void print(T &value)
{
	std::cout << value << std::endl;
}

#endif