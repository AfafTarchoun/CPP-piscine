/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:48 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/20 02:29:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Test with a value that is in the container
    std::vector<int>::iterator it = easyfind(vec, 2);
    std::cout << "Value found: " << *it << std::endl;

    // Test with a value that is not in the container
    try
    {
        easyfind(vec, 6);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
