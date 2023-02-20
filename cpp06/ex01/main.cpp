/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:54 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:15:10 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serialization.hpp"

int main()
{
    Data d;
    d.x = 42;
    d.y = 3.14;
    d.z = 'X';

    uintptr_t serializedPtr = Serializer::serialize(&d);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedPtr == &d)
        std::cout << "Serialization and deserialization succeeded!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;
    return 0;
}
