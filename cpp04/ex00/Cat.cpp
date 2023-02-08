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
}

Cat::Cat(const Cat& other) = default;

Cat& Cat::operator=(const Cat& other) = default;

Cat::Cat(Cat&& other) = default;

Cat& Cat::operator=(Cat& other);

Cat::~Cat() = default;

void Cat::makeSound() const
{
    std::cout << "Cat sound!" << std::endl;
}

//Wrong cat methodes

WrongCat::WrongCat(const std::string& name): WrongAnimals(name)
{
    _type= "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) = default;

WrongCat& WrongCat::operator=(const WrongCat& other) = default;

WrongCat::WrongCat(WrongCat&& other) = default;

WrongCat& WrongCat::operator=(WrongCat&& other) = default;

WrongCat::~WrongCat() = default;

void WrongCat::makeSound() const
{
std::cout << "Wrong Cat sound!" << std::endl;
}