/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:23:58 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 19:28:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    _type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    setType(type);
    std::cout << "Animal paramitrized Constructor Called\n";
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    this->_type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout <<"Animal destructor called" << std::endl;
}

void Animal::setType(std::string a) 
{
    this->_type = a;
}

void Animal::makeSound() const
{
    std::cout << "some animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

//Wrong Animals methodes
WrongAnimal::WrongAnimal() : Animal()
{
    std::cout << "WrongAnimal Constructor Called\n";
}

WrongAnimal::WrongAnimal(std::string type) : Animal(type)
{
    std::cout << "WrongAnimal paramitrized Constructor Called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) :Animal(other)
{
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout <<"definitely not an animal sound" << std::endl;
}