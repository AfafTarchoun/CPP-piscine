/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/12 12:14:27 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Scavy");
    std::cout << "Attack damage: " << scavTrap.getAttackDamage() << std::endl;
    scavTrap.attack("Enemy");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    return 0;
}
