/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:21:59 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 07:16:37 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

/*In this example, the constructors that take an integer or a floating-point number as a parameter convert the value
to the corresponding fixed-point representation by left-shifting the integer value
or multiplying the floating-point value by 1 << _fractionalBits respectively.
The toFloat() member function converts the fixed-point value back to a floating-point value by dividing by 1 << _fractionalBits,
and the toInt() member function converts the fixed-point value to an integer by right-shifting _fractionalBits places.
The operator<< overloads the insertion operator allowing us to print the float value of the fixed point number.
Also, It is worth noting that this class does not handle the rounding or overflow errors that might occur during operations or conversions.*/