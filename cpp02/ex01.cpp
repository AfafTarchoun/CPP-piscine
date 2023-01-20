/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:21:59 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/20 00:31:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Fixed {
    private:
        int _rawValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);
};

Fixed::Fixed() : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawValue = (int)(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    _rawValue = other._rawValue;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    _rawValue = other._rawValue;
    return *this;
}

float Fixed::toFloat() const {
    return (float)_rawValue / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _rawValue >> _fractionalBits;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawValue = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}

/*In this example, the constructors that take an integer or a floating-point number as a parameter convert the value to the corresponding fixed-point representation by left-shifting the integer value or multiplying the floating-point value by 1 << _fractionalBits respectively. The toFloat() member function converts the fixed-point value back to a floating-point value by dividing by 1 << _fractionalBits, and the toInt() member function converts the fixed-point value to an integer by right-shifting _fractionalBits places.
The operator<< overloads the insertion operator allowing us to print the float value of the fixed point number.
Also, It is worth noting that this class does not handle the rounding or overflow errors that might occur during operations or conversions.*/