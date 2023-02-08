/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 08:53:29 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Clappy", 10, 50);
    std::cout << "Attack damage: " << clapTrap.getAttackDamage() << std::endl;
    clapTrap.setAttackDamage(15);
    std::cout << "Attack damage: " << clapTrap.getAttackDamage() << std::endl;

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(10);
    clapTrap.beRepaired(10);

    ClapTrap clapTrap2 = clapTrap;
    ClapTrap clapTrap3("Clappy 3", 20, 100);
    clapTrap3 = clapTrap2;

    return 0;
}
