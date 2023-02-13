/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:15:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
   public:
        Animal();
        Animal(std::string _type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        void    setType(std::string a);
        std::string getType() const;
    protected:
        std::string _type;
};

class Dog : public Animal
{
    private:
        Brain *B;
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void getIdeas();
        void makeSound() const;
};

class Cat : public Animal
{
    private:
        Brain *B;
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void getIdeas();
        void makeSound() const;
};

class WrongAnimal : public Animal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        void    setType(std::string type);
        std::string getType(void) const ;
        virtual void makeSound() const;
};

#endif