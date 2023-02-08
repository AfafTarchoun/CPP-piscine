/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:23:58 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:32:51 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animals::Animals(const std::string& name) : _name(name)
{
    _type = "Animal";
}

Animals::Animals(const Animals& other) = default;

Animals& Animals::operator=(const Animals& other) = default;

Animals::Animals(Animals&& other) = default;

Animals& Animals::operator=(Animals&& other) = default;

Animals::~Animals() = default;

void Animals::makeSound() const
{
    std::cout << "Animals sound!" << std::endl;
}
std::string Animals::getType() const
{
    return _type;
}
std::string Animals::getName() const
{
    return _name;
}

//Wrong Animals methodes
WrongAnimals::WrongAnimals(const std::string& name): Animals(name)
{
    _type = "WrongAnimals";
}

WrongAnimals::WrongAnimals(const WrongAnimals& other) = default;

WrongAnimals& WrongAnimals::operator=(const WrongAnimals& other) = default;

WrongAnimals::WrongAnimals(WrongAnimals&& other) = default;

WrongAnimals& WrongAnimals::operator=(WrongAnimals&& other) = default;

WrongAnimals::~WrongAnimals() = default;

void WrongAnimals::makeSound() const
{
    std::cout << "Wrong Animals sound!" << std::endl;
}
