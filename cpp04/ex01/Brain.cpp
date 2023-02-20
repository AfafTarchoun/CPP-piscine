/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:28:07 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/15 21:23:58 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "ideas";
    std::cout << "Brain Default Constuctor" << std::endl;
}

Brain::Brain(std::string ideas)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = ideas;
    std::cout << "Brain Paramitrized constructor" << std::endl;
}

Brain::Brain(Brain & B)
{
    *this = B;
}

Brain & Brain::operator=(Brain const & B)
{
    for(int i = 0; i < 100; i++)
	{
        this->ideas[i] = B.ideas[i];
	}
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

void    Brain::setIdeas(std::string idea, int n)
{
	this->ideas[n] = idea;
	std::cout << "setIdeas Function Called" << std::endl;
}

std::string Brain::getIdeas(int n) const 
{
	return (this->ideas[n]);
}