/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:12 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:16:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.hpp"

std::string truncate(std::string str, int width);
class PhoneBook
{
    private:
        Contact contacts[8];
        int current_index = 0;
    public:
        void setcont(Contact contact)
        {
            if (current_index < 8)
            {
                contacts[current_index] = contact;
                current_index++;
            }
            else
            {
                for (int i = 0; i < 7; i++)
                    contacts[i] = contacts[i+1];
                contacts[7] = contact;
            }
        }
        void search_contact(int index)
        {
            if (index >= 1 && index <= current_index)
        	{
                Contact contact = contacts[index-1];
                std::cout << "First Name: " << contact.get_first() << std::endl;
                std::cout << "Last Name: " << contact.get_last() << std::endl;
                std::cout << "Nickname: " << contact.get_nickname() << std::endl;
                std::cout << "Phone Number: " << contact.get_nb() << std::endl;
                std::cout << "Darkest Secret: " << contact.get_dark() << std::endl;
            }
        	else
                std::cout << "Invalid index" << std::endl;
        }
        void display_contacts()
        {
            std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
            for (int i = 0; i < current_index; i++)
            {
                std::cout << std::setw(10) << i+1 << " | ";
                std::cout << std::setw(10) << truncate(contacts[i].get_first(),10) << " | ";
                std::cout << std::setw(10) << truncate(contacts[i].get_last(),10) << " | ";
                std::cout << std::setw(10) << truncate(contacts[i].get_nickname(),10) << std::endl;
            }
        }
};
#endif