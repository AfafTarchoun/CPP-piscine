/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:30 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 00:48:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <iostream>

template <class T>
class Array
{
    public:
        // Construction with no parameter
        Array();
        // Construction with an unsigned int n as a parameter
        Array(unsigned int n);
        // Copy constructor
        Array(const Array<T>& other);
        // Assignment operator
        Array<T>& operator=(const Array<T>& other);
        // Destructor
        ~Array();
        // Subscript operator
        T& operator[](int index);
        // Size function
        int size() const;
    private:
        int    m_size;
        T              *m_data;
};
#include "Array.tpp"
#endif