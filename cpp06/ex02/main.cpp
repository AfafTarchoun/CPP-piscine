/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:59 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 03:48:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    int r = rand() % 3;
    if (r == 0) {
        return new A;
    } else if (r == 1) {
        return new B;
    } else {
        return new C;
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
    A* a = dynamic_cast<A*>(&p);
    B* b = dynamic_cast<B*>(&p);
    C* c = dynamic_cast<C*>(&p);
    if (a != nullptr) {
        std::cout << "A" << std::endl;
    } else if (b != nullptr) {
        std::cout << "B" << std::endl;
    } else if (c != nullptr) {
        std::cout << "C" << std::endl;
    }
}

int main() {
    Base* p = generate();
    identify(p);
    Base& r = *p;
    identify(r);
    delete p;
    return 0;
}
/*The generate function generates a random number between 0 and 2, and return a new object of the corresponding class.
The identify function with pointer parameter uses dynamic_cast to check if the passed pointer is of type A, B or C, and prints the corresponding class.
The identify function with reference parameter uses dynamic_cast to check if the passed reference is of type A, B or C, and prints the corresponding class.

In the test program, we call the generate function to create a random object of one of the classes A, B or C, then pass the pointer to the identify function to print the actual type of the object. Then we pass the reference to the identify function to print the actual type of the object.

Note that dynamic_cast operation will only work if the class has atleast one virtual function defined.*/