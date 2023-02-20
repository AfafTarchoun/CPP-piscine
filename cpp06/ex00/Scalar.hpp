/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:11:46 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:13:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <string>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const std::string& s);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        static void   convert(const std::string& value);
    private:
        std::string value;
        ~ScalarConverter();
};
#endif