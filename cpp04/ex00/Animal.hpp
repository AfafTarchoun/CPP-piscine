/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/15 21:10:30 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
   public:
        Animal();
        Animal(std::string _type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const;
        void    setType(std::string tt);
        std::string getType() const;
    protected:
        std::string _type;
};

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound() const;
};

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void makeSound() const;
};

class WrongAnimal
{
    protected :
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        void    setType(std::string type);
        std::string getType(void) const ;
        void makeSound() const;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string name);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();
        void makeSound() const;
};

#endif