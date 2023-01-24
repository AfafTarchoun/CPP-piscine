/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:32:55 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
    unsigned int _maxHitPoints;

public:
    ClapTrap(std::string name, unsigned int attackDamage, unsigned int maxHitPoints) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(attackDamage), _maxHitPoints(maxHitPoints) {
        std::cout << _name << ": ClapTrap constructor called" << std::endl;
    }

    ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage), _maxHitPoints(other._maxHitPoints) {
        std::cout << _name << ": ClapTrap copy constructor called" << std::endl;
    }

    ClapTrap& operator=(const ClapTrap& other) {
        if (this == &other) {
            return *this;
        }
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _maxHitPoints = other._maxHitPoints;
        std::cout << _name << ": ClapTrap assignment operator called" << std::endl;
        return *this;
    }

    ~ClapTrap() {
        std::cout << _name << ": ClapTrap destructor called" << std::endl;
    }

    void setAttackDamage(unsigned int value) {
        if (value < 0) {
            std::cout << _name << ": Invalid attack damage value" << std::endl;
            return;
        }
        _attackDamage = value;
    }
    unsigned int getAttackDamage() const { return _attackDamage; }
    void setMaxHitPoints(unsigned int value) {
        if (value < _hitPoints) {
            std::cout << _name << ": Invalid max hit points value" << std::endl;
            return;
        }
        _maxHitPoints = value;
    }
    unsigned int getMaxHitPoints() const { return _maxHitPoints; }

    void attack(const std::string& target) {
        if (_energyPoints < 1) {
            std::cout << _name << ": Not enough energy to attack" << std::endl;
            return;
        }

        std::cout << _name << ": attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }

    void takeDamage(unsigned int amount) {
        if (amount > _hitPoints) {
            amount = _hitPoints;
        }

        _hitPoints -= amount;
        std::cout << _name << ": takes " << amount << " points of damage!" << std::endl;
    }

    void beRepaired(unsigned int amount) {
        if (_energyPoints < 1) {
            std::cout << _name << ": Not enough energy to repair" << std::endl;
            return;
        }

        unsigned int newHitPoints = _hitPoints + amount;
        if (newHitPoints > _maxHitPoints) {
            _hitPoints = _maxHitPoints;
        } else {
            _hitPoints = newHitPoints;
        }

        std::cout << _name << ": repairs " << amount << " hit points!" << std::endl;
        _energyPoints--;
    }
};
int main() {
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