#ifndef ESAYFIND_HPP
#define ESAYFIND_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

#endif