/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:00 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:33:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name) : ClapTrap(name, 20, 100) {
        setHitPoints(100);
        setEnergyPoints(50);
        std::cout << _name << ": ScavTrap constructor called" << std::endl;
    }

    ScavTrap(const ScavTrap& other) : ClapTrap(other) {
        std::cout << _name << ": ScavTrap copy constructor called" << std::endl;
    }

    ScavTrap& operator=(const ScavTrap& other) {
        ClapTrap::operator=(other);
        std::cout << _name << ": ScavTrap assignment operator called" << std::endl;
        return *this;
    }

    ~ScavTrap() {
        std::cout << _name << ": ScavTrap destructor called" << std::endl;
    }
    void attack(const std::string& target) {
        if (_energyPoints < 1) {
            std::cout << _name << ": Not enough energy to attack" << std::endl;
            return;
        }

        std::cout << _name << ": attacks " << target << " with a fancy attack, causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }

    void guardGate() {
        std::cout << _name << ": is now in Gatekeeper mode!" << std::endl;
    }
};
/*As you can see, the ScavTrap class inherits from the ClapTrap class using the public keyword, which means that all the public members of the ClapTrap class will be accessible from the ScavTrap class.
The ScavTrap class overloads the constructors and destructor, so that it can print different messages when creating, copying or destroying an instance of the class.
It also overloads the attack function so that it can print a different message and have a different behavior if needed.
It also has its own special capacity, the guardGate function, which displays a message when it is called.*/
int main() {
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
/*As you can see, we create an instance of the ScavTrap class, then we call its functions, and we also copy it and assign it to other instances of the class.
When creating, copying or destroying an instance of the ScavTrap class, the constructors and destructor of the ClapTrap class will also be called, and the proper construction/destruction chaining will be shown in the output.
*/
void testConstructors() {
    std::cout << "Testing constructors:" << std::endl;
    ScavTrap scavTrap("Scavy");
    std::cout << std::endl;
}

void testCopyConstructor() {
    std::cout << "Testing copy constructor:" << std::endl;
    ScavTrap scavTrap("Scavy");
    ScavTrap scavTrap2(scavTrap);
    std::cout << std::endl;
}

void testAssignmentOperator() {
    std::cout << "Testing assignment operator:" << std::endl;
    ScavTrap scavTrap("Scavy");
    ScavTrap scavTrap2("Scavy 2");
    scavTrap2 = scavTrap;
    std::cout << std::endl;
}

void testDestructor() {
    std::cout << "Testing destructor:" << std::endl;
    {
        ScavTrap scavTrap("Scavy");
    }
    std::cout << std::endl;
}


