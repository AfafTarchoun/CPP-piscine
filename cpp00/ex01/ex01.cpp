/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 02:37:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

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
        {
            book.display_contacts();
            int index;
            std::cout << "Enter index of contact to display: ";
            std::cin >> index;
            if (!isdigit(index) || index < 1)
            {
                std::cout << "Invalid index!" << std::endl;
                // continue;
            }
            else
                book.search_contact(index);
		}
        else if (input == "EXIT")
            exit (1);
        else
			std::cout << "Invalid choice!" << std::endl;
    }
    return 0;
}
