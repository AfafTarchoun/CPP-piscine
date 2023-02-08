/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 09:52:01 by atarchou         ###   ########.fr       */
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

    ScavTrap scavTrap2 = scavTrap;
    ScavTrap scavTrap3("Scavy 3");
    scavTrap3 = scavTrap2;

    return 0;
}
// int main()
// {
//     ClapTrap clapTrap("Clappy", 10, 50);
//     std::cout << "Attack damage: " << clapTrap.getAttackDamage() << std::endl;
//     clapTrap.setAttackDamage(15);
//     std::cout << "Attack damage: " << clapTrap.getAttackDamage() << std::endl;

//     clapTrap.attack("Enemy");
//     clapTrap.takeDamage(5);
//     clapTrap.beRepaired(10);
//     clapTrap.beRepaired(10);

//     ClapTrap clapTrap2 = clapTrap;
//     ClapTrap clapTrap3("Clappy 3", 20, 100);
//     clapTrap3 = clapTrap2;

//     return 0;
// }
