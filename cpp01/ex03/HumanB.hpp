/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:33 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 04:20:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
        HumanB(std::string n) : name(n), weapon(nullptr) {}
        ~HumanB() {delete weapon;}
        void setWeapon(Weapon w);
        std::string getName() const { return name; }
        void attack()
        {
            if (weapon != nullptr)
                std::cout << name << " attacks with their " << weapon->getType() << std::endl;
            else
                std::cout << name << " has no weapon to attack with" << std::endl;
        }
};
#endif