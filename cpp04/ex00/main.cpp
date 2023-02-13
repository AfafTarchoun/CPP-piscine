/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:26:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " "<< std::endl;
    std::cout << i->getType() << " "<< std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    return 0;
}

