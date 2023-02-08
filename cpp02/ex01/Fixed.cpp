/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:13:11 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 07:17:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawValue = (value << this->_fractionalBits);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawValue = other._rawValue;
    return *this;
}

float Fixed::toFloat() const
{
    return ((float)_rawValue) / (1 << this->_fractionalBits);
}

int Fixed::toInt() const
{
    return _rawValue >> this->_fractionalBits;
}

// int Fixed::getRawBits() const
// {
//     std::cout << "getRawBits member function called" << std::endl;
//     return _rawValue;
// }

// void Fixed::setRawBits(int const raw)
// {
//     std::cout << "setRawBits member function called" << std::endl;
//     _rawValue = raw;
// }

std::ostream &operator<<(std::ostream &op, const Fixed &f)
{
    op << f.toFloat();
    return op;
}