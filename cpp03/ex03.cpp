/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:15 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:33:15 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class DiamondTrap : public virtual FragTrap, public virtual ScavTrap {
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();
    void whoAmI();

private:
    std::string _clap_name;
};

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    _clap_name = "_clap_name";
    std::cout << _name << ": DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {
    _clap_name = name + "_clap_name";
    std::cout << _name << ": DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other) {
    _clap_name = other._clap_name;
    std::cout << _name << ": DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _clap_name = other._clap_name;
    }
    std::cout << _name << ": DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~Diamond Trap() {
std::cout << _name << ": DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
std::cout << _name << ": My ClapTrap name is " << _clap_name << std::endl;
}
/*This implementation solves the diamond inheritance problem by using virtual inheritance for the FragTrap and ScavTrap base classes.
This ensures that only one instance of the ClapTrap class is created in the DiamondTrap class. */

int main() {
    DiamondTrap dt1;
    DiamondTrap dt2("dt2");
    DiamondTrap dt3(dt2);
    dt1 = dt3;
    dt1.whoAmI();
    dt1.attack("target");
    dt1.guardGate();
    dt1.highFivesGuys();
    return 0;
}
