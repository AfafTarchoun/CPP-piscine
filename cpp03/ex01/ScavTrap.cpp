/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:00 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:00:54 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 20, 100)
{
    this->_hitPoints = 100;
    this->_energyPoints= 50;
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

/*As you can see, the ScavTrap class inherits from the ClapTrap class using the public keyword, which means that all the public members of the ClapTrap class will be accessible from the ScavTrap class.
The ScavTrap class overloads the constructors and destructor, so that it can print different messages when creating, copying or destroying an instance of the class.
It also overloads the attack function so that it can print a different message and have a different behavior if needed.
It also has its own special capacity, the guardGate function, which displays a message when it is called.*/

/*As you can see, we create an instance of the ScavTrap class, then we call its functions, and we also copy it and assign it to other instances of the class.
When creating, copying or destroying an instance of the ScavTrap class, the constructors and destructor of the ClapTrap class will also be called, and the proper construction/destruction chaining will be shown in the output.
*/
// void testConstructors() {
//     std::cout << "Testing constructors:" << std::endl;
//     ScavTrap scavTrap("Scavy");
//     std::cout << std::endl;
// }

// void testCopyConstructor() {
//     std::cout << "Testing copy constructor:" << std::endl;
//     ScavTrap scavTrap("Scavy");
//     ScavTrap scavTrap2(scavTrap);
//     std::cout << std::endl;
// }

// void testAssignmentOperator() {
//     std::cout << "Testing assignment operator:" << std::endl;
//     ScavTrap scavTrap("Scavy");
//     ScavTrap scavTrap2("Scavy 2");
//     scavTrap2 = scavTrap;
//     std::cout << std::endl;
// }

// void testDestructor() {
//     std::cout << "Testing destructor:" << std::endl;
//     {
//         ScavTrap scavTrap("Scavy");
//     }
//     std::cout << std::endl;
// }



