/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:00 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/12 12:19:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints= 50;
    this->_attackDamage = 20;
    std::cout << this->_name << ": ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << this->_name << ": ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << this->_name << ": ScavTrap assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << ": ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints < 1)
    {
        std::cout << this->_name << ": Not enough energy to attack" << std::endl;
        return;
    }
    std::cout << this->_name << ": attacks " << target << " with a fancy attack, causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << this->_name << ": is now in Gatekeeper mode!" << std::endl;
}
