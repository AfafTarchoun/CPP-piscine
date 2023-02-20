/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:40:33 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 05:11:05 by atarchou         ###   ########.fr       */
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
        HumanB(std::string n);
        void        setWeapon(Weapon &w);
        std::string getName();
        void        setName(std::string Name);
        void        attack();
};
#endif