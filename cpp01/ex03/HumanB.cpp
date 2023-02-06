/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:30 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 04:19:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) {this->name = n;}

void    HumanB::setName(std::string Name)
{
    this->name = Name;
}

std::string HumanB::getName(void)
{
    return this->name;
}

void HumanB::setWeapon(Weapon &w)
{
    this->weapon = &w;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}