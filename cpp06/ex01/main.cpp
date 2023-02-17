/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:54 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 03:49:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

struct Data {
    int x;
    double y;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data d = {5, 6.7};
    Data* ptr = &d;
    uintptr_t raw = serialize(ptr);
    Data* ptr2 = deserialize(raw);
    if (ptr == ptr2) {
        std::cout << "The pointers match!" << std::endl;
    } else {
        std::cout << "The pointers do not match." << std::endl;
    }
    return 0;
}
/*The serialize function takes a pointer to a Data object and converts it to an uintptr_t by using the reinterpret_cast operator. The deserialize function does the opposite: it takes an uintptr_t and converts it back to a pointer to a Data object.

In the test program, we create a Data object and a pointer to it, then pass the pointer to the serialize function to get the raw value. Then we pass that raw value to the deserialize function to get the pointer back. Then we check if the original pointer and the pointer got back from deserialize are equal.

Note that this implementation is dependent on the size of a pointer on the machine where it is run and is not recommended for use in production systems. The main use case for this is for debugging or for serializing a pointer temporarily.*/