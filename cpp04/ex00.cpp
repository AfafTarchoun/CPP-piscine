/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:33:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:33:24 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*creating the base class Animal.
In this class, we'll have a protected attribute _type which will be a string representing the type of animal,
and a public method makeSound() which will be pure virtual (i.e., it will be left unimplemented in the base class,
but will be overridden by derived classes to provide different functionality).*/
#include <iostream>
#include <string>

class Animals {
public:
    Animals(const std::string& name) : _name(name) {
        _type = "Animal";
    }
    Animals(const Animals& other) = default;
    Animals& operator=(const Animals& other) = default;
    Animals(Animals&& other) = default;
    Animals& operator=(Animals&& other) = default;
    virtual ~Animals() = default;
    virtual void makeSound() const {
        std::cout << "Animals sound!" << std::endl;
    }
    std::string getType() const {
        return _type;
    }
    std::string getName() const {
        return _name;
    }
private:
    std::string _name;
    std::string _type;
};

/*Next, we'll create the Dog class which will inherit from Animal. In the constructor of this class,
we'll set the _type attribute to "Dog" so that we know it's a dog.
We'll also override the makeSound() method to output the sound that a dog makes.*/

class Dog : public Animals {
public:
    Dog(const std::string& name) : Animals(name) {
        _type = "Dog";
    }
    Dog(const Dog& other) = default;
    Dog& operator=(const Dog& other) = default;
    Dog(Dog&& other) = default;
    Dog& operator=(Dog&& other) = default;
    ~Dog() = default;
    void makeSound() const {
        std::cout << "Dog sound!" << std::endl;
    }
};

/*the Cat class which will also inherit from Animals. In this class,
we'll set the _type attribute to "Cat" and override the makeSound() method to output the sound that a cat makes.*/

class Cat : public Animals {
public:
    Cat(const std::string& name) : Animals(name) {
        _type = "Cat";
    }
    Cat(const Cat& other) = default;
    Cat& operator=(const Cat& other) = default;
    Cat(Cat&& other) = default;
    Cat& operator=(Cat&& other) = default;
    ~Cat() = default;
    void makeSound() const {
        std::cout << "Cat sound!" << std::endl;
    }
};

class WrongAnimals : public Animals {
public:
    WrongAnimals(const std::string& name): Animals(name) {
        _type = "WrongAnimals";
    }
    WrongAnimals(const WrongAnimals& other) = default;
    WrongAnimals& operator=(const WrongAnimals& other) = default;
    WrongAnimals(WrongAnimals&& other) = default;
    WrongAnimals& operator=(WrongAnimals&& other) = default;
    ~WrongAnimals() = default;
    void makeSound() const {
        std::cout << "Wrong Animals sound!" << std::endl;
    }
};

class WrongCat : public WrongAnimals {
public:
    WrongCat(const std::string& name): WrongAnimals(name) {
        _type= "WrongCat";
}
WrongCat(const WrongCat& other) = default;
WrongCat& operator=(const WrongCat& other) = default;
WrongCat(WrongCat&& other) = default;
WrongCat& operator=(WrongCat&& other) = default;
~WrongCat() = default;
void makeSound() const {
std::cout << "Wrong Cat sound!" << std::endl;
}
};

int main() {
const Animals* meta = new Animals("meta");
const Animals* j = new Dog("j");
const Animals* i = new Cat("i");
std::cout << j->getType() << " " << j->getName() << std::endl;
std::cout << i->getType() << " " << i->getName() << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
const Animals* wmeta = new WrongAnimals("wmeta");
const Animals* wi = new WrongCat("wi");
std::cout << wi->getType() << " " << wi->getName() << std::endl;
wi->makeSound();
wmeta->makeSound();

delete meta;
delete j;
delete i;
delete wmeta;
delete wi;
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
