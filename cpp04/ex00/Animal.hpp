/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 10:35:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animals
{
    protected:
        Animals(const std::string& name);
        Animals(const Animals& other);
        Animals& operator=(const Animals& other);
        Animals(Animals&& other);
        Animals& operator=(Animals&& other);
        virtual ~Animals();
        virtual void makeSound() const;
        std::string getType() const;
        std::string getName() const;
    private:
        std::string _name;
        std::string _type;
};

class Dog : public Animals
{
    public:
        Dog(const std::string& name);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        Dog(Dog&& other);
        Dog& operator=(Dog&& other);
        ~Dog();
        void makeSound() const;
};

class Cat : public Animals
{
    public:
        Cat(const std::string& name);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        Cat(Cat&& other);
        Cat& operator=(Cat&& other);
        ~Cat();
        void makeSound() const;
};

class WrongAnimals : public Animals
{
    public:
        WrongAnimals(const std::string& name);
        WrongAnimals(const WrongAnimals& other);
        WrongAnimals& operator=(const WrongAnimals& other);
        WrongAnimals(WrongAnimals&& other);
        WrongAnimals& operator=(WrongAnimals&& other);
        ~WrongAnimals();
        void makeSound() const;
};

class WrongCat : public WrongAnimals
{
    public:
        WrongCat(const std::string& name);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        WrongCat(WrongCat&& other);
        WrongCat& operator=(WrongCat&& other);
        ~WrongCat();
        void makeSound() const;
};

#endif