#include "ex02.hpp"

Base* generate() {
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::bad_cast& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::bad_cast& e) {
                std::cout << "Not A, B or C" << std::endl;
            }
        }
    }
}

int main()
{
    srand(time(0));
    Base* b = generate();
    identify(b);
    identify(*b);
    delete b;
    return 0;
}
/*In this example, the generate() function generates a random integer between 0 and 2 
and returns a new instance of class A, B or C as a Base pointer. 
The identify(Base* p) function uses the dynamic_cast operator to check the type of the object pointed to by p and prints the actual type of the object ("A", "B" or "C"). 
The identify(Base& p) function uses the dynamic_cast operator with try-catch statements to check the type of the object and prints the actual type of the object ("A", "B" or "C"). The main() function generates a random object, identifies it using both identify functions, 
and deletes the object to prevent memory leaks.

The srand(time(0)) line is used to seed the random number generator.
The srand() function is used to initialize the random number generator with a seed value, 
which is passed as an argument. The time(0) argument is used to provide a unique seed value 
based on the current time. This is done to ensure that each time the program is run,
a different sequence of random numbers is generated. This is important in our case,
as we want to randomly generate instances of the A, B, or C classes in the generate() function.



*/