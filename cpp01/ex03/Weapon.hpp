/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 05:11:22 by atarchou         ###   ########.fr       */
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
    public:
        Weapon();
        Weapon(std::string type);
        const std::string &getType() const;
        void     setType(std::string type);
};

#endif