/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:13:30 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 07:57:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream &operator<<(std::ostream& op, const Fixed& o)
{
    op << o.toFloat();
    return (op);
}

//canonical orthodox form requirements
Fixed::Fixed() : _fixed(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixed = value << this->i;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixed = roundf(value * (1 << this->i));
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

//setters and getters
int Fixed::getRawBits(void) const
{
    return (this->_fixed);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

//operators
Fixed & Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed = other._fixed;
    return *this;
}

Fixed Fixed::operator++()
{
    _fixed++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}
Fixed Fixed::operator--()
{
    _fixed--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool   Fixed::operator!=(Fixed const &other) const
{
    return ((this->getRawBits() != other.getRawBits()));
}

bool   Fixed::operator>=(Fixed const &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

bool   Fixed::operator<=(Fixed const &other) const
{
    return ((this->getRawBits() <= other.getRawBits()));
}

bool   Fixed::operator<(Fixed const &other) const
{
    return ((this->getRawBits() < other.getRawBits()));
}

bool   Fixed::operator>(Fixed const &other) const 
{
    return ((this->getRawBits() > other.getRawBits()));
}

//to int and to float functions
float Fixed::toFloat(void) const
{
    return ((float) this->_fixed / (1 << this->i));
}

int Fixed::toInt(void) const
{
    return (this->_fixed << this->i);
}

//min max functions
Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return (a);
    else
        return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return (a);
    else
        return (b);
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
    if(b > a)
        return (a);
    else
        return (b);
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
    if(a > b)
        return (a);
    else
        return (b);
}