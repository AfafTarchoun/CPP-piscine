
#include "Fixed.hpp"

std::ostream &operator<<(std::ostream& op, const Fixed& o)
{
    op << o.toFloat();
    return (op);
}

Fixed::Fixed() : _rawValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_rawValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_rawValue = roundf(value * (1 << this->_fractionalBits));
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

Fixed & Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_rawValue = other._rawValue;
    return *this;
}

Fixed Fixed::operator++()
{
    _rawValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    ++_rawValue;
    return *this;
}

Fixed Fixed::operator--()
{
    _rawValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    --_rawValue;
    return *this;
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
    Fixed tmp;
    tmp.setRawBits(this->_rawValue + other._rawValue);
    return tmp;
}

Fixed Fixed::operator-(Fixed const &other) const
{
    Fixed tmp;
    tmp.setRawBits(this->_rawValue - other._rawValue);
    return tmp;
}

Fixed Fixed::operator/(Fixed const &other) const
{
    Fixed tmp;
    tmp.setRawBits(((this->_rawValue) / other._rawValue) << this->_fractionalBits);
    return tmp;
}

Fixed Fixed::operator*(Fixed const &other) const
{
    Fixed tmp;
    tmp.setRawBits(((this->_rawValue) * other._rawValue) << this->_fractionalBits);
    return tmp;
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

float Fixed::toFloat(void) const
{
    //printf("%f\n", (float) this->_fixed / (1 << this->i));
    return ((float) this->_rawValue / (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called\n";
    return (this->_rawValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->_rawValue = raw;
}

int Fixed::toInt(void) const
{
    return (this->_rawValue << this->_fractionalBits);
}


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