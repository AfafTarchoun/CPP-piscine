/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:14:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:32:41 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {}
        Zombie() : name("Unnamed Zombie") {}
        std::string getName() const { return name; }
        ~Zombie()
        {
            std::cout << name << " is destroyed" << std::endl;
        }
};
void announce(Zombie &zombie);
Zombie* zombiesHorde(int N, std::string name);
#endif