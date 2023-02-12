/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:52 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:27:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog(const std::string& name) : Animals(name)
{
    _type = "Dog";
    std::cout <<_name << " Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) :Animals(other)
{}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
      Animals::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout <<_name << " Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout <<_name << " Dog sound!" << std::endl;
}