/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:06:35 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:11:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 30, 100)
{
    _hitPoints = 100;
    _energyPoints = 100;
    std::cout << _name << ": FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << _name << ": FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << _name << ": FragTrap assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << _name << ": FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints < 1) {
        std::cout << _name << ": Not enough energy to attack" << std::endl;
        return;
    }
    std::cout << _name << ": attacks " << target << " with a powerful attack, causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void FragTrap::highFivesGuys()
{
    std::cout << _name << ": requests high fives from the guys!" << std::endl;
}