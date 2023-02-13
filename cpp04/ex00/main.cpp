/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:35:03 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

int main()
{
    const Animal* meta = new Animal("meta");
    const Animal* j = new Dog("j");
    const Animal* i = new Cat("i");
    std::cout << j->getType() << " "<< std::endl;
    std::cout << i->getType() << " "<< std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    // delete meta;
    // delete j;
    // delete i;
    return 0;
}
/*n this code, I have created a base class `Animals` which has a protected attribute `_type` and a public attribute `_name`.
The `Animals` class also has a constructor which takes a string as a parameter and assigns it to the `_name` attribute.
The `Animals` class also has a virtual function `makeSound` which outputs the sound of an animal. 
I have then created two classes `Dog` and `Cat` which inherit from the `Animals` class.
Both classes have their own constructors which call the parent class constructor and set the _type attribute to "Dog" or "Cat" respectively.
Both classes also have their own implementation of the `makeSound` function which outputs the specific sound of that animal.
Then I have created two classes `WrongAnimals` and `WrongCat` which also inherit from the `Animals` class, the same way as `Dog` and `Cat`,
but with different _type and different output for the `makeSound()` function.
In the main function, I have created pointers to the `Animals`, `Dog`, `Cat`, `WrongAnimals` and `WrongCat` classes
and called the appropriate functions to check that each class is working as intended.*/
