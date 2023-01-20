/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:36:43 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/18 00:32:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {}
        void announce()
        {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
        ~Zombie()
        {
            std::cout << name << " is destroyed" << std::endl;
        }
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);