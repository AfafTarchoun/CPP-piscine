/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:13:15 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/08 07:56:47 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP
#include <math.h>
#include <iostream>

class Fixed
{
    private:
        int _fixed;
        static const int i = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        float toFloat() const;
        int   toInt() const;
};

std::ostream &operator<<(std::ostream& op, const Fixed& f);

#endif