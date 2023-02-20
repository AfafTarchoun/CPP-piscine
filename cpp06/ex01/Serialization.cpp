/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:47:16 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:13:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serialization.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer constructor" << std::endl;
}

Serializer::Serializer(const Serializer& )
{
    std::cout << "Serializer copy constructor" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& )
{
    std::cout << "Serializer copy assignment operator" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}