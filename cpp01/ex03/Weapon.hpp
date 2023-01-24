/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 04:14:11 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;
        bool is_null;
    public:
        Weapon(std::string t);
        const std::string& getType() const {return type;}
        void setType(std::string t) {type = t;}
        bool isNull() const {return is_null;}
};

#endif