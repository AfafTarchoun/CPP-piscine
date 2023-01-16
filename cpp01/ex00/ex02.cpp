/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:51 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 15:29:54 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}

/*In this program, a string variable str is initialized to "HI THIS IS BRAIN".
stringPTR is a pointer to the string, and stringREF is a reference to the string.
The program first prints the memory address of the string variable, the memory address held by stringPTR,
and the memory address held by stringREF.
Then, it prints the value of the string variable, the value pointed to by stringPTR, and the value pointed to by stringREF.
As you can see, references and pointers are similar in the sense that they both allow you to manipulate memory addresses,
but references are more like an alias to a variable,
you can use them directly and you don't need to use the * operator to get the value of the variable that it refers to.
Also, references can not be null, once you initialize a reference to a variable, it will always refer to that variable.
While pointers can be reassigned to refer to a different memory address, or set to null.*/