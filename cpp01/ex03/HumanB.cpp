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

void setWeapon(Weapon w)
{
    Weapon* weapon;
    
    if (weapon != nullptr)
        delete weapon;
    weapon = new Weapon(w);
}
// void attack(Weapon* weapon, HumanB &hb)
// {
//     if (weapon != nullptr)
//         std::cout << hb.getName() << " attacks with their " << weapon->getType() << std::endl;
//     else
//         std::cout << hb.getName() << " has no weapon to attack with" << std::endl;
// }