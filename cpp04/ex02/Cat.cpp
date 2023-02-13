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
#include "Brain.hpp"
Cat::Cat()
{
    B = new Brain();
    std::cout << "Cat Default constructor Called\n";
}

Cat::Cat(std::string name) : Animal(name)
{
    B = new Brain();
    std::cout << " Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :Animal(other)
{
    this->B = new Brain();
    *B = *other.B;
}

Cat& Cat::operator=(const Cat& other)
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

Cat::~Cat()
{
    delete B;
    std::cout << " Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << " Cat sound!" << std::endl;
}

void    Cat::getIdeas(void)
{
    for(int i = 0; i < 100; i++)
        std::cout << B->getIdeas(i) << std::endl; 
}