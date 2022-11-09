/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:29 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/09 17:53:06 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// PhoneBook::PhoneBook(void)
// {
//     std::cout << "Constructor" << std::endl;
//     return;
// }

// PhoneBook::~PhoneBook(void)
// {
//     std::cout << "Destructor" << std::endl;
//     return;
// }

void    add(void)
{
    std::string name;

    std::cout << "Please, enter your first name: " ;
    std::getline (std::cin,name);
    std::cout << "Please, enter your last name: ";
    std::getline (std::cin,name);
    std::cout << "Please, enter your nickname: ";
    std::getline (std::cin,name);
    std::cout << "Please, enter your phone number: ";
    std::getline (std::cin,name);
    std::cout << "Please, enter your darkest secret: ";
    std::getline (std::cin,name);
}

int main()
{
    //PhoneBook book;
    // Contact    contact;
    
    // std::cout << contact.nickname << std::endl;
    
    // std::string name;

    // std::cout << "Please, enter your full name: ";
    // std::getline (std::cin,name);
    char *input; 
    std::cout << "Please enter :ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::cin >> input;
        if (std::strcmp("ADD",input) == 0)
        {
            // std::cout<< "lol" << std::endl;
            add();
        }
        else if (std::strcmp("SEARCH", input) == 0)
        {
            std::cout<<"ha"<<std::endl;
        }
        else if (std::strcmp("EXIT", input) == 0)
            return 0;
    }
    return 0;
}