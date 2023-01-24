/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:25:11 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:34:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombiesHorde(N, "Horde Zombie ");
    for (int i = 0; i < N; i++)
    {
        announce(horde[i]);
    }
    delete[] horde;
    return 0;
}

/*In the above function, we use the new operator to allocate a block of memory large enough to hold N Zombie objects,
this memory is on the heap, it's then creates N zombies,
each one is initialized with the given name and an index.
The function returns a pointer to the first zombie in the horde.*/

/*This will create a horde of 5 zombies, each one will have a different name, and it will call the announce() function for each one of them.
The delete operator with [] is used to release the block of memory that was allocated for the Zombies horde.
It's important to use the delete[] operator when you allocated memory using the new[] operator,
if you used the delete operator instead of delete[] it will cause undefined behavior and potentially a memory leak.*/