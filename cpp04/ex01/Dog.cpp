/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:52 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:35:41 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    B = new Brain();
    _type = "Dog";
    std::cout << "Dog Default constructor" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
    B = new Brain();
    std::cout <<"Dog parameterized constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->B = new Brain();
    *B = *other.B;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this->B)
    {
        delete this->B;
        this->B = new Brain();
    }
    for (int i = 0; i < 100; i++)
        this->B->setIdeas(other.B->getIdeas(i), i);
    this->_type = other._type;
    return *this;
}

Dog::~Dog()
{
    delete B;
    std::cout <<"Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof woof" << std::endl;
}

void    Dog::getIdeas(void)
{
    for(int i = 0; i < 100; i++)
        std::cout << B->getIdeas(i) << std::endl; 
}