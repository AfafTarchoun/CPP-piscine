/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/12 12:24:27 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap FragTrap("Fragy");
    std::cout << "Attack damage: " << FragTrap.getAttackDamage() << std::endl;
    FragTrap.attack("Enemy");
    FragTrap.takeDamage(5);
    FragTrap.beRepaired(10);
    FragTrap.highFivesGuys();
    return 0;
}