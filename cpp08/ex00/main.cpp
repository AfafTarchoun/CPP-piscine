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

#include "easyfind.hpp"


int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Test with a value that is in the container
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << "Value found: " << *it << std::endl;

    // Test with a value that is not in the container
    try {
        std::vector<int>::iterator it2 = easyfind(vec, 6);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}


/*This function template takes in a container of any type and an integer value.
It uses the find algorithm from the STL to search for the first occurrence of the given value in the container.
If the value is not found, it throws an exception with a message indicating that the value was not found.
If the value is found, it prints the index of the first occurrence.
/**/