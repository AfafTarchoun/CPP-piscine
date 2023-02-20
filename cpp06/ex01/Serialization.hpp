/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:47:13 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:22 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

struct Data 
{
    int    x;
    double y;
    char   z;
};

class Serializer
{
    private:
        ~Serializer();
    public:
        Serializer();
        Serializer(const Serializer& );
        Serializer& operator=(const Serializer& );
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif