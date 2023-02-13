/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:26:38 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:35:24 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
Cat::Cat()
{
    B = new Brain();
    _type = "Cat";
    std::cout << "Cat Default constructor" << std::endl;
}

Cat::Cat(std::string name) : Animal(name)
{
    B = new Brain();
    std::cout << "Cat parameterized constructor" << std::endl;
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
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meaw meaw" << std::endl;
}

void    Cat::getIdeas(void)
{
    for(int i = 0; i < 100; i++)
        std::cout << B->getIdeas(i) << std::endl; 
}
