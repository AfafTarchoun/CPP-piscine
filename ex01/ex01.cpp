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

void    add_info(PhoneBook *phonebook)
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
    phonebook->setcont(contact);
}

void   search(PhoneBook *book)
{
    Contact contact;
    int count;

    count = book->counting();
    if (count == 0)
        std::cout << "Empty Phonebook: 0 contacts"<< std::endl;
    else 
    {
        std::cout << "|**********|**********|**********|**********|" << std::endl;
        std::cout << "│" << std::setw(10)  << "index";
        std::cout << "│" << std::setw(10) << "first name";
        std::cout << "│" << std::setw(10)  << "last name";
        std::cout << "│" << std::setw(10)  << "nickname" << "│" << std::endl;
        std::cout << "|**********|**********|**********|**********|" << std::endl;

    }

}

int main()
{
    PhoneBook book;

    std::string input; 
    std::cout << "Please enter :ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::getline(std::cin, input);
        if (input == "ADD")
            add_info(&book);
        else if (input == "SEARCH")
            search(&book);
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}