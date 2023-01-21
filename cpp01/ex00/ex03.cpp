/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:25:04 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 15:59:49 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon {
    private:
        string type;
    public:
        Weapon(string t) : type(t) {}
        const string& getType() const {return type;}
        void setType(string t) {type = t;}
};

class HumanA {
    private:
        Weapon weapon;
        string name;
    public:
        HumanA(string n, Weapon w) : name(n), weapon(w) {}
        void attack() {cout << name << " attacks with their " << weapon.getType() << endl;}
};

class HumanB {
    private:
        Weapon* weapon;
        string name;
    public:
        HumanB(string n) : name(n), weapon(nullptr) {}
        ~HumanB() {delete weapon;}
        void setWeapon(Weapon w) {
            if (weapon != nullptr) {
                delete weapon;
            }
            weapon = new Weapon(w);
        }
        void attack() {
            if (weapon != nullptr) {
                cout << name << " attacks with their " << weapon->getType() << endl;
            } else {
                cout << name << " has no weapon to attack with" << endl;
            }
        }
};

int main() {
    {
        Weapon club("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
