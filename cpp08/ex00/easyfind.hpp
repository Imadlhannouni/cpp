#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int &to_find)
{
    typename T::iterator it;

    it = find(container.begin(), container.end(), to_find);
    if (it == container.end())
        throw (std::out_of_range("Element not found"));
    return it;
}

#endif