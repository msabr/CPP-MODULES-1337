/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:52:07 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:52:08 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESAYFIND_HPP
#define ESAYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

#endif