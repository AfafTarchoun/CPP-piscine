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
    std::cout << _name << " Animal constructor called" << std::endl;
}

Animals::Animals(const Animals& other)
{
    _type = other._type;
}

Animals& Animals::operator=(const Animals& other)
{
    if (this != &other)
      _type = other._type;
    return *this;
}

Animals::~Animals()
{
    std::cout << _name <<" Animal destructor called" << std::endl;
}

void Animals::makeSound() const
{
    std::cout << _name << " Animals sound!" << std::endl;
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
    std::cout << _name << " Wrong animal constructor" << std::endl;
}

WrongAnimals::WrongAnimals(const WrongAnimals& other) : Animals(other._type) {}

WrongAnimals& WrongAnimals::operator=(const WrongAnimals& other)
{
  if (this != &other)
    _type = other._type;
  return *this;
}

WrongAnimals::~WrongAnimals()
{
    std::cout << _name << " Wrong animal destructor" << std::endl;
}

void WrongAnimals::makeSound() const
{
    std::cout <<_name << " Wrong Animals sound!" << std::endl;
}
