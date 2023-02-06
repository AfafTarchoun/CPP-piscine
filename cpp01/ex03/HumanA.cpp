/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:36 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:40:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

std::string HumanA::getName(void)
{
    return (this->name);
}

void    HumanA::setName(std::string Name)
{
    this->name = Name;
}

HumanA::HumanA(std::string n, Weapon &W) :
    weapon(W)
{
    this->name = n;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}