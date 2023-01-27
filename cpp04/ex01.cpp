
#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& type) : _type(type) {
        std::cout << _type << " constructor called" << std::endl;
    }
    Animal(const Animal& other) = default;
    Animal& operator=(const Animal& other) = default;
    Animal(Animal&& other) = default;
    Animal& operator=(Animals&& other) = default;
    virtual ~Animal() {
        std::cout << _type << " destructor called" << std::endl;
    }
    virtual void makeSound() const {
        std::cout << _type << " sound!" << std::endl;
    }
    std::string getType() const {
        return _type;
    }
private:
    std::string _type;
};

class Dog : public Animal {
public:
    Dog() : Animal("Dog") {
        _brain = new Brain();
    }
    Dog(const Dog& other) {
        _brain = new Brain(*other._brain);
    }
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            delete _brain;
            _brain = new Brain(*other._brain);
        }
        return *this;
    }
    Dog(Dog&& other) = default;
    Dog& operator=(Dog&& other) = default;
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
        delete _brain;
    }
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
private:
    Brain* _brain;
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat") {
        _brain = new Brain();
    }
    Cat(const Cat& other) {
        _brain = new Brain(*other._brain);
    }
    Cat& operator=(const Cat& other) {
        if (this != &other) {
            delete _brain;
            _brain = new Brain(*other._brain);
        }
        return *this;
    }
    Cat(Cat&& other) = default;
    Cat& operator=(Cat&& other) = default;
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
        delete _brain;
    }
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
private:
    Brain* _brain;
};

class Brain {
public:
    Brain() {
        for (int i = 0; i < 100; i++) {
            ideas[i] = "Idea " + std::to_string(i);
        }
    }
    Brain& operator=(const Brain& other) {
        if (this != &other) {
            for (int i = 0; i < 100; i++) {
                ideas[i] = other.ideas[i];
            }
        }
        return *this;
    }
    std::string ideas[100];
};

int main() {
    const int numAnimals = 10;
    Animal* animalArray[numAnimals];
    for (int i = 0; i < numAnimals / 2; i++) {
        animalArray[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animalArray[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++) {
        delete animalArray[i];
    }
    return 0;
}
/*int main() {
    const int numAnimals = 10;
    Animal* animalArray[numAnimals];
    for (int i = 0; i < numAnimals / 2; i++) {
        animalArray[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animalArray[i] = new Cat();
    }

    //Test 1: Print the type of each animal in the array
    std::cout << "Test 1: Print the type of each animal in the array" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        std::cout << animalArray[i]->getType() << std::endl;
    }

    //Test 2: Print the sound made by each animal in the array
    std::cout << "Test 2: Print the sound made by each animal in the array" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        animalArray[i]->makeSound();
    }

    //Test 3: Test copy constructor and assignment operator for Dog and Cat objects
    std::cout << "Test 3: Test copy constructor and assignment operator for Dog and Cat objects" << std::endl;
    Dog dog1("dog1");
    Dog dog2 = dog1;
    Dog dog3("dog3");
    dog3 = dog1;
    Cat cat1("cat1");
    Cat cat2 = cat1;
    Cat cat3("cat3");
    cat3 = cat1;

    //Test 4: Print the sound made by each animal in the array after copying
    std::cout << "Test 4: Print the sound made by each animal in the array after copying" << std::endl;
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    for (int i = 0; i < numAnimals; i++) {
        delete animalArray[i];
    }
    return 0;
}
*/
