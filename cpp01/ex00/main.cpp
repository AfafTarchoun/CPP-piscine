/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:48:56 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 05:11:51 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* heapZombies = newZombie("Heap Zombie");
    heapZombies->announce();
    randomChump("Stack Zombie");
    delete heapZombies;
    return (0);
}
