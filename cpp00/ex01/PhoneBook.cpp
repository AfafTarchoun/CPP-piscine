/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:00:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/04 22:00:55 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::setcont(Contact contact)
{
    if (this->current_index < 8)
    {
        this->contacts[this->current_index] = contact;
        this->current_index++;
    }
    else
    {
        for (int i = 0; i < 7; i++)
            this->contacts[i] = this->contacts[i+1];
        this->contacts[7] = contact;
    }
}

void PhoneBook::search_contact(int index)
{
    if ((index >= 1 && index <= this->current_index))
    {
        Contact contact = this->contacts[index-1];
        std::cout << "First Name: " << contact.get_first() << std::endl;
        std::cout << "Last Name: " << contact.get_last() << std::endl;
        std::cout << "Nickname: " << contact.get_nickname() << std::endl;
        std::cout << "Phone Number: " << contact.get_nb() << std::endl;
        std::cout << "Darkest Secret: " << contact.get_dark() << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}

void PhoneBook::display_contacts()
{
    std::cout << "     Index | First Name | Last Name | Nickname" << std::endl;
    for (int i = 0; i < this->current_index; i++)
    {
        std::cout << std::right << std::setw(10) << i+1 << " | ";
        std::cout << std::right << std::setw(10) << truncate(this->contacts[i].get_first()) << " | ";
        std::cout << std::right << std::setw(10) << truncate(this->contacts[i].get_last()) << " | ";
        std::cout << std::right << std::setw(10) << truncate(this->contacts[i].get_nickname()) << std::endl;
    }
}
