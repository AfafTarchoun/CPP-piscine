/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:07 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:33:07 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class FragTrap : public ClapTrap {
public:
    FragTrap(std::string name) : ClapTrap(name, 30, 100) {
        setHitPoints(100);
        setEnergyPoints(100);
        std::cout << _name << ": FragTrap constructor called" << std::endl;
    }

    FragTrap(const FragTrap& other) : ClapTrap(other) {
        std::cout << _name << ": FragTrap copy constructor called" << std::endl;
    }

    FragTrap& operator=(const FragTrap& other) {
        ClapTrap::operator=(other);
        std::cout << _name << ": FragTrap assignment operator called" << std::endl;
        return *this;
    }

    ~FragTrap() {
        std::cout << _name << ": FragTrap destructor called" << std::endl;
    }

    void attack(const std::string& target) {
        if (_energyPoints < 1) {
            std::cout << _name << ": Not enough energy to attack" << std::endl;
            return;
        }

        std::cout << _name << ": attacks " << target << " with a powerful attack, causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }

    void highFivesGuys() {
        std::cout << _name << ": requests high fives from the guys!" << std::endl;
    }
};
/*As you can see, the FragTrap class inherits from the ClapTrap class using the public keyword, which means that all the public members of the ClapTrap class will be accessible from the FragTrap class.
The FragTrap class overloads the constructors and destructor, so that it can print different messages when creating, copying or destroying an instance of the class.
It also overloads the attack function so that it can print a different message and have a different behavior if needed.
It also has its own special capacity, the highFivesGuys function, which displays a message when it is called.
*/

void testFragTrapConstructors() {
    std::cout << "Testing FragTrap constructors:" << std::endl;
    FragTrap fragTrap("Fraggy");
    std::cout << std::endl;
}
void testFragTrapCopyConstructor() {
    std::cout << "Testing FragTrap copy constructor:" << std::endl;
    FragTrap fragTrap("Fraggy");
    FragTrap fragTrap2(fragTrap);
    std::cout << std::endl;
}

void testFragTrapAssignmentOperator() {
    std::cout << "Testing FragTrap assignment operator:" << std::endl;
    FragTrap fragTrap("Fraggy");
    FragTrap fragTrap2("Fraggy 2");
    fragTrap2 = fragTrap;
    std::cout << std::endl;
}

void testFragTrapDestructor() {
    std::cout << "Testing FragTrap destructor:" << std::endl;
    {
        FragTrap fragTrap("Fraggy");
    }
    std::cout << std::endl;
}