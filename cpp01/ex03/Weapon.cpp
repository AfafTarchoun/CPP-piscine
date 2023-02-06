/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:39:34 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:53:08 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

void Weapon::setType(std::string t)
{
    this->type = t;
}

std::string Weapon::getType(void)
{
    return this->type;
}

Weapon::Weapon(std::string type) 
{
    setType(type);
}

