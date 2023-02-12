/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:38 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:40:32 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat(const std::string& name) : Animals(name)
{
   this->_type = "Cat";
    std::cout <<_name << " Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :Animals(other){}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
      Animals::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout <<_name << " Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout <<_name << " Cat sound!" << std::endl;
}

//Wrong cat methodes

WrongCat::WrongCat(const std::string& name): WrongAnimals(name)
{
    _type= "WrongCat";
    std::cout <<_name << " Wrong cat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimals(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
  if (this != &other)
    WrongAnimals::operator=(other);
  return *this;
}

WrongCat::~WrongCat()
{
    std::cout <<_name << " Wrong cat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout <<_name << " Wrong Cat sound!" << std::endl;
}
