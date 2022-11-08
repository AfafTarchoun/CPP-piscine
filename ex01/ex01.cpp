/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:29 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/08 17:24:00 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Constructor" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Destructor" << std::endl;
    return;
}

int main()
{
    //PhoneBook book;
    Contact    contact;
    
    std::cout << contact.nickname << std::endl;
    
    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline (std::cin,name);
    // std::cout << "Please enter :ADD, SEARCH, EXIT" << std::endl;
    // while (1)
    // {
    //     std::cin >> argv[0];
    //     if (std::strcmp("ADD", argv[0]) == 0)
    //     {
    //         std::cout<< "lol" << std::endl;
    //     }
    //     else if (std::strcmp("SEARCH", argv[0]) == 0)
    //     {
    //         std::cout<<"ha"<<std::endl;
    //     }
    //     else if (std::strcmp("EXIT", argv[0]) == 0)
    //         return 0;
    // }
    return 0;
}