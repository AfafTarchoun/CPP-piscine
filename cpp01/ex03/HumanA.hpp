/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:39:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:50:06 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon weapon;
        std::string name;
    public:
        HumanA(std::string n, Weapon w) : name(n), weapon(w) {}
        void attack()
        {
            std::cout << name << " attacks with their " << weapon.getType() << std::endl;
        }
};

#endif