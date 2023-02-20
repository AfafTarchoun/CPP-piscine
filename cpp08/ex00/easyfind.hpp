/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:43 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 20:20:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>

template <typename T> 
typename T::iterator easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::invalid_argument("Value not found in container.");
    }
    std::cout << "First occurrence of " << value << " is at index " << std::distance(container.begin(), it) << std::endl;
    return it;
}

#endif