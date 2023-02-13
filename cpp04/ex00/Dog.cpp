/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:52 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:24:04 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog Default constructor Called\n";
}

Dog::Dog(std::string name) : Animal(name)
{
    std::cout <<"Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    this->_type = other._type;
    return *this;
}

Dog::~Dog()
{
    std::cout <<"Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof woof" << std::endl;
}