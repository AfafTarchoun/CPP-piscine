/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:37 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:41:37 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "array.hpp"

int main()
{
    Array<int> a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    Array<int> b(a);

    for (unsigned int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    Array<int> c;
    c = a;

    for (unsigned int i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*This is an example of how to use the class and how it should work,
it creates two arrays a and b and initializes them with the same values,
then it prints the values of b, it creates another array c and assigns the values of a to it,
then it prints the values of c.
The program should output: 1 2 3 4 5 1 2 3 4 5*/