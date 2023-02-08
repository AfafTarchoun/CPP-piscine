/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:46:36 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 09:44:17 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, unsigned int attackDamage, unsigned int maxHitPoints)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = attackDamage;
    _maxHitPoints = maxHitPoints;
    std::cout << _name << ": ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
{
    _name=other._name;
    _hitPoints=other._hitPoints;
    _energyPoints=other._energyPoints;
    _attackDamage=other._attackDamage;
    _maxHitPoints=other._maxHitPoints;
    std::cout << _name << ": ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return (*this);
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    _maxHitPoints = other._maxHitPoints;
    std::cout << _name << ": ClapTrap assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << ": ClapTrap destructor called" << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int value)
{
    if (value < 0)
    {
        std::cout << _name << ": Invalid attack damage value" << std::endl;
        return;
    }
    _attackDamage = value;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::setMaxHitPoints(unsigned int value)
{
    if (value < _hitPoints)
    {
        std::cout << _name << ": Invalid max hit points value" << std::endl;
        return;
    }
    _maxHitPoints = value;
}

unsigned int ClapTrap::getMaxHitPoints() const
{
    return _maxHitPoints;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints < 1)
    {
        std::cout << _name << ": Not enough energy to attack" << std::endl;
        return;
    }
    std::cout << _name << ": attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > _hitPoints)
        amount = _hitPoints;
    _hitPoints -= amount;
    std::cout << _name << ": takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints < 1)
    {
        std::cout << _name << ": Not enough energy to repair" << std::endl;
        return;
    }
    unsigned int newHitPoints = _hitPoints + amount;
    if (newHitPoints > _maxHitPoints)
        _hitPoints = _maxHitPoints;
    else
        _hitPoints = newHitPoints;
    std::cout << _name << ": repairs " << amount << " hit points!" << std::endl;
    _energyPoints--;
}