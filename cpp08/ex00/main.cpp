/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:48 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:41:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
void easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::exception("Value not found in container.");
    }
    std::cout << "First occurrence of " << value << " is at index " << std::distance(container.begin(), it) << std::endl;
}
/*This function template takes in a container of any type and an integer value.
It uses the find algorithm from the STL to search for the first occurrence of the given value in the container.
If the value is not found, it throws an exception with a message indicating that the value was not found.
If the value is found, it prints the index of the first occurrence.

Here is an example of how to use the easyfind function:*/
// std::vector<int> v = {1, 2, 3, 4, 5};
// easyfind(v, 3);
// It will output:

// First occurrence of 3 is at index 2
// You can also test it with other types of containers like list,set etc.

// std::list<int> l = {1, 2, 3, 4, 5};
// easyfind(l, 3);
// It will also output :

// First occurrence of 3 is at index 2