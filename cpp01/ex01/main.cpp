/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:25:11 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 05:12:09 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombiesHorde(N, "Horde Zombie ");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
