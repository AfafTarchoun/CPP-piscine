/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:13:11 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 07:56:47 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed = (value << this->i);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixed = roundf(value * (1 << this->i));
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
    this->_fixed = other._fixed;
    return *this;
}

float Fixed::toFloat() const
{
    return ((float)_fixed) / (1 << this->i);
}

int Fixed::toInt() const
{
    return _fixed >> this->i;
}

std::ostream &operator<<(std::ostream &op, const Fixed &f)
{
    op << f.toFloat();
    return op;
}