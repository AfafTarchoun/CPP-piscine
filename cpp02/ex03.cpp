/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:32:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 00:32:29 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


To overload the comparison operators, you can add the following member functions to your class:

class Fixed {
  // ...
  public:
    bool operator>(const Fixed& other) const { return _value > other._value; }
    bool operator<(const Fixed& other) const { return _value < other._value; }
    bool operator>=(const Fixed& other) const { return _value >= other._value; }
    bool operator<=(const Fixed& other) const { return _value <= other._value; }
    bool operator==(const Fixed& other) const { return _value == other._value; }
    bool operator!=(const Fixed& other) const { return _value != other._value; }
  // ...
};

To overload the arithmetic operators, you can add the following member functions to your class:
class Fixed {
  // ...
  public:
    Fixed operator+(const Fixed& other) const { return Fixed(_value + other._value); }
    Fixed operator-(const Fixed& other) const { return Fixed(_value - other._value); }
    Fixed operator*(const Fixed& other) const { return Fixed(roundf(_value * other._value)); }
    Fixed operator/(const Fixed& other) const { return Fixed(_value / other._value); }
  // ...
};


To overload the increment/decrement operators, you can add the following member functions to your class:
class Fixed {
  // ...
  public:
    Fixed& operator++() { _value += _epsilon; return *this; }
    Fixed operator++(int) { Fixed temp(*this); _value += _epsilon; return temp; }
    Fixed& operator--() { _value -= _epsilon; return *this; }
    Fixed operator--(int) { Fixed temp(*this); _value -= _epsilon; return temp; }
  // ...
};

To add the min and max member functions, you can add the following static member functions to your class:
class Fixed {
  // ...
  public:
    static const Fixed& min(const Fixed& a, const Fixed& b) { return a < b ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) { return a > b ? a : b; }
  // ...
};

And for the constant version of min and max member functions you can add the following static member function to your class:
class Fixed {
  // ...
  public:
    static const Fixed& min(const Fixed& a, const Fixed& b) { return a < b ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) { return a > b ? a : b; }
    static const Fixed& min(const Fixed& a, const Fixed& b) const { return a < b ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) const { return a > b ? a : b; }
  // ...
};
Please note that, you need to handle the case of division by zero in the operator /, otherwise it will cause a runtime error. Additionally, You need to handle the case where the result of arithmetic operation exceeds the maximum represent




