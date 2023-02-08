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
}

Dog::Dog(const Dog& other) = default;

Dog& Dog::operator=(const Dog& other) = default;

Dog::Dog(Dog&& other) = default;

Dog& Dog::operator=(Dog&& other) = default;

Dog::~Dog() = default;

void Dog::makeSound() const
{
    std::cout << "Dog sound!" << std::endl;
}