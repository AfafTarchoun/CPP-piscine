/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:43 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:41:43 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma other

template <typename T>
template T::iterator easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::exception("Value not found in container.");
    }
    std::cout << "First occurrence of " << value << " is at index " << std::distance(container.begin(), it) << std::endl;
    return it;
}