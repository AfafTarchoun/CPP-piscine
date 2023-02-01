/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:38:44 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:38:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class AAnimals {
public:
    virtual ~Animals() = 0;
    virtual void makeSound() const = 0;
    std::string getType() const;
    std::string getName() const;

protected:
    AAnimals(const std::string& name, const std::string& type);
    AAnimals(const AAnimals& other);
    AAnimals& operator=(const AAnimals& other);
    AAnimals(AAnimals&& other) = delete;
    AAnimals& operator=(AAnimals&& other) = delete;

private:
    std::string _name;
    std::string _type;
};

inline AAnimals::~Animals() = default;
inline AAnimals::AAnimals(const std::string& name, const std::string& type) : _name(name), _type(type) {}
inline AAnimals::AAnimals(const AAnimals& other) : _name(other._name), _type(other._type) {}
inline AAnimals& AAnimals::operator=(const AAnimals& other) {
    if (this != &other) {
        _name = other._name;
        _type = other._type;
    }
    return *this;
}
inline std::string AAnimals::getType() const { return _type; }
inline std::string AAnimals::getName() const { return _name; }

class Dog : public AAnimals {
public:
    Dog(const std::string& name);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    void makeSound() const;

private:
    Brain* _brain;
};

inline Dog::Dog(const std::string& name) : AAnimals(name, "Dog") {
    _brain = new Brain();
}
inline Dog::Dog(const Dog& other) : AAnimals(other) {
    _brain = new Brain(*other._brain);
}
inline Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimals::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}
inline Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}
inline void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

class Cat : public AAnimals {
public:
    Cat(const std::string& name);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound() const;

private:
    Brain* _brain;
};

inline Cat::Cat(const std::string& name) : AAnimals(name, "Cat") {
    _brain = new Brain();
}

inline Cat::Cat(const Cat& other) : AAnimals(other) {
    _brain = new Brain(*other._brain);
}
inline Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimals::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}
inline Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}
inline void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
/*In this implementation, the AAnimals class has its constructor and assignment operator protected and its destructor made pure virtual to prevent any direct instantiation of the class. The Dog and Cat classes are derived from AAnimals and provide their own implementations for the pure virtual functions and their own constructors.

*/
