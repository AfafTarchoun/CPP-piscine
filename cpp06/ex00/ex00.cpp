/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:47 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:50 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

void handleCharLiteral(std::string input)
{
    if (input.length() != 3 || input[2] != '\'')
    {
        std::cout << "Invalid char literal." << std::endl;
        return;
    }
    char c = input[1];
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    // Convert to int
    int i = c;
    std::cout << "int: " << i << std::endl;
    // Convert to float
    float f = c;
    std::cout << "float: " << f << "f" << std::endl;
    // Convert to double
    double d = c;
    std::cout << "double: " << d << std::endl;
}

void handleIntLiteral(std::string input)
{
    char* end;
    long long l = strtoll(input.c_str(), &end, 10);

    if (l > INT_MAX || l < INT_MIN)
        std::cout << "int: impossible (overflow)" << std::endl;
    else
    {
        int i = l;
        std::cout << "int: " << i << std::endl;
        // Convert to char
        if (!isprint(i))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << (char)i << "'" << std::endl;
        // Convert to float
        float f = i;
        std::cout << "float: " << f << "f" << std::endl;
        // Convert to double
        double d = i;
        std::cout << "double: " << d << std::endl;
    }
}

void handleFloatLiteral(std::string input)
{
    char* end;
    float f = strtof(input.c_str(), &end);

    if (std::isinf(f) || std::isnan(f))
        std::cout << "float: " << input << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    // Convert to char
    if (!isprint((int)f))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << (char)f << "'" << std::endl;
    // Convert to int
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: impossible (overflow)" << std::endl;
    else
    {
        int i = f;
        std::cout << "int: " << i << std::endl;
    }
    // Convert to double
    double d = f;
    std::cout << "double: " << d << std::endl;
}

void handleDoubleLiteral(std::string input)
{
    char* end;
    double d = strtod(input.c_str(), &end);

    if (std::isinf(d) || std::isnan(d))
        std::cout << "double: " << input << std::endl;
    else
        std::cout << "double: " << d << std::endl;
    // Convert to char
    if (!isprint((int)d))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << (char)d << "'" << std::endl;
    // Convert to int
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible (overflow)" << std::endl;
    else
    {
        int i = d;
        std::cout << "int: " << i << std::endl;
    }
    // Convert to float
    float f = d;
    std::cout << "float: " << f << "f" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Please provide an input" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    if (input.length() == 1)
        handleCharLiteral(input);
    else if (input.find(".") == std::string::npos)
        handleIntLiteral(input);
    else if (input.find("f") != std::string::npos)
        handleFloatLiteral(input);
    else
        handleDoubleLiteral(input);
    return 0;
}