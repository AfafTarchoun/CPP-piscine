/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:58 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/20 02:20:51 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Span parameterized constructor called" << std::endl;
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span & other)
{
    _data = other._data;
    return (*this);
}

void Span::addNumber(int num)
{
    if (_data.size() == _n)
    {
        throw std::length_error("Span is already full.");
    }
    _data.push_back(num);
}

void Span::addRange(std::vector<int> &_data2)
{
    std::vector <int>::iterator iter;
    iter = _data2.begin();
    int distance = _data2.size();
    for (int i = 0 ; i < distance; i++)
    {
        _data.push_back(*iter);
        iter++;
    }
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
    {
        throw std::length_error("Span has less than 2 numbers.");
    }
    std::vector<int> sortedData = _data;
    sort(sortedData.begin(), sortedData.end());
    int tmp = sortedData[1] - sortedData[0];
    for (unsigned int i = 1; i < sortedData.size() - 1; i++)
    {
        if ((sortedData[i + 1] - sortedData[i]) < tmp)
            tmp = sortedData[i + 1] - sortedData[i];
    }
    return (tmp);
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
    {
        throw std::length_error("Span has less than 2 numbers.");
    }
    return (*max_element(_data.begin(), _data.end()) - *min_element(_data.begin(), _data.end()));
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}