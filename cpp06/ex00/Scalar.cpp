/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:47 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:38:39 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Scalar constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string& s) : value(s)
{
    std::cout << "Scalar parametrized constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) : value(other.value)
{
    std::cout << "Scalar copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    std::cout << "Scalar copy assignemet operator" << std::endl;
    if (this != &other)
      value = other.value;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Scalar destructor" << std::endl;
    
}

void ScalarConverter::convert(const std::string& value)
{
    char    c;
    int     i;
    float   f;
    double  d;
    
    // Try to convert to char
    try
    {
        c = static_cast<char>(std::stoi(value.c_str()));
        if (c < 32 || c > 126)
            std::cout << "Cannot convert to char: non-displayable character" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }
    
    // Try to convert to int
    try
    {
        i = static_cast<int>(std::stoi(value.c_str()));
        std::cout << "int: " << i << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }
    
    // Try to convert to float
    try
    {
        f = static_cast<float>(std::strtof(value.c_str(), nullptr));
        if (f == std::numeric_limits<float>::infinity())
            std::cout << "float: +inff" << std::endl;
        else if (f == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;
        else if (std::isnan(f))
            std::cout << "float: nanf" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }
    
    // Try to convert to double
    try
    {
        d = static_cast<double>(std::strtod(value.c_str(), nullptr));
        if (d == std::numeric_limits<double>::infinity())
            std::cout << "double: +inf" << std::endl;
        else if (d == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
        else if (std::isnan(d))
            std::cout << "double: nan" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    catch (...) 
    {
        std::cout << "impossible" << std::endl;
    }
}

