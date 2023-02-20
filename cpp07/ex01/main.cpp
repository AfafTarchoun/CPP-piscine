/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:22 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 01:13:16 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void printT(T x)
{
    std::cout << x << " ";
}

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    std::string stringArr[] = {"Hello", "World", "!"};

    iter(intArr, 5, printT);
    std::cout << std::endl;
    iter(stringArr, 3, printT);
    std::cout << std::endl;
    return 0;
}
