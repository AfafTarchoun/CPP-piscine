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

PhoneBook::PhoneBook(void)
{
    this->index=0;
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void    add_info(PhoneBook phonebook)
{
    std::string name;
    Contact contact;

    std::cout << "Please, enter your first name: " ;
    std::getline (std::cin,name);
    contact.set_first(name);
    std::cout << "Please, enter your last name: ";
    std::getline (std::cin,name);
    contact.set_last(name);
    std::cout << "Please, enter your nickname: ";
    std::getline (std::cin,name);
    contact.set_nickname(name);
    std::cout << "Please, enter your phone number: ";
    std::getline (std::cin,name);
    contact.set_nb(name);
    std::cout << "Please, enter your darkest secret: ";
    std::getline (std::cin,name);
    contact.set_dark(name);
    phonebook.add_contact(contact);
}

void   search(PhoneBook book)
{
    
}

int main()
{
    PhoneBook book;
    // Contact    contact;
    
    // std::cout << contact.nickname << std::endl;
    
    // std::string name;

    // std::cout << "Please, enter your full name: ";
    // std::getline (std::cin,name);
    std::string input; 
    std::cout << "Please enter :ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            add_info(book);
        }
        else if (input == "SEARCH")
        {
            std::cout<<"ha"<<std::endl;
            search();
        }
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}