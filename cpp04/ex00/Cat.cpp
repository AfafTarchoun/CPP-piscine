/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:38 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:24:02 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Cat Default constructor Called\n";
}

Cat::Cat(std::string name) : Animal(name)
{
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :Animal(other)
{
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    this->_type = other._type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meaw meaw" << std::endl;
}

//Wrong cat methodes

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor Called\n";
}

WrongCat::WrongCat(std::string name): WrongAnimal(name)
{
    std::cout << "Wrong cat parameterized constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) :WrongAnimal(other)
{
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    this->type = other.type;
  return *this;
}

WrongCat::~WrongCat()
{
    std::cout <<"Wrong cat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "definitely not meaw" << std::endl;
}
