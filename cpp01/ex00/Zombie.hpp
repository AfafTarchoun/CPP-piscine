/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:36:43 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:17:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {}
        std::string getName() const { return name; }
        ~Zombie()
        {
            std::cout << name << " is destroyed" << std::endl;
        }
};
void announce(Zombie &zombie);
Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif