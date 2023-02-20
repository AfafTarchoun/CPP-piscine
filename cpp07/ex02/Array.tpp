/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:14:06 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 01:02:57 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

// Construction with no parameter
template <class T>
Array<T>::Array() : m_size(0), m_data()
{
    std::cout <<"Constructor called"<< std::endl;
}

// Construction with an unsigned int n as a parameter
template <class T>
Array<T>::Array(unsigned int n)
{
    m_data = new T[n];
    m_size = n;
    std::cout <<"Parameterized Constructor called"<< std::endl;
}

// Copy constructor
template <class T>
Array<T>::Array(const Array<T>& other)
{
    if (this != &other)
        m_data = new T (*other.m_data);
    *this = other;
    std::cout <<"Copy Constructor called"<< std::endl;
}

// Assignment operator
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    std::cout <<"Copy assignement operator called"<< std::endl;
    if (this != &other)
    {
        delete[] m_data;
        m_data = new T[*other.m_data];
    }
    m_size = other.m_size;
    *m_data = *other.m_data;
    return *this;
}

// Destructor
template <class T>
Array<T>::~Array()
{
    std::cout <<"Destructor called"<< std::endl;
    delete[] m_data;
}

// Subscript operator
template <class T>
T& Array<T>::operator[](int index)
{
    try
    {
        if (index > m_size)
            // throw (index);
            throw std::exception();
    }
    catch (...)
    {
        std::cout <<"out of range"<<std::endl;
    }
    return m_data[index];
}

// Size function
template <class T>
int Array<T>::size() const
{
    return m_size;
}

#endif