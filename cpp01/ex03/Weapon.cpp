/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:39:34 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 03:07:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

void Weapon::setType(std::string t)
{
    this->type = t;
}

const std::string& Weapon::getType() const
{
    return this->type;
}

Weapon::Weapon(std::string type) 
{
    setType(type);
}

