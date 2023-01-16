/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 13:30:16 by atarchou         ###   ########.fr       */
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

std::string truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void search(PhoneBook *book)
{
	int index;
	int count;

	count = book->counting();
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i=0; i < book->counting(); i++)
	{
		Contact contact;
		contact = book->getcount(i);
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncate(contact.get_first());
		std::cout << "|" << std::setw(10) << truncate(contact.get_last());
		std::cout << "|" << std::setw(10) << truncate(contact.get_nickname()) << "|" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	if (count > 0)
	{
		std::cout << "Please enter an index for relevant information: ";
		while (!(std::cin >> index) || index > count || index < 1)
		{
			std::cin.clear();
			std::cout << "Invalid input. Please enter an index between 1 and " << count << ": ";
		}
		index--;
		Contact tmp;
		tmp = book->getcount(index);
		std::cout << std::endl;
		std::cout << "First name - " << tmp.get_first() << std::endl;
		std::cout << "Last name - " << tmp.get_last() << std::endl;
		std::cout << "Nickname - " << tmp.get_nickname() << std::endl;
		std::cout << "Phone number - " << tmp.get_nb() << std::endl;
		std::cout << "Darkest secret - " << tmp.get_dark() << std::endl;
	}
	else
	{
		std::cout << "Table is empty!" << std::endl;
	}
}
// void   search(PhoneBook *book)
// {
//     Contact contact;
//     int count;

//     count = book->counting();
//     if (count == 0)
//         std::cout << "Empty Phonebook: 0 contacts"<< std::endl;
//     else 
//     {
//         std::cout << "|**********|**********|**********|**********|" << std::endl;
//         std::cout << "│" << std::setw(10)  << "index";
//         std::cout << "│" << std::setw(10) << "first name";
//         std::cout << "│" << std::setw(10)  << "last name";
//         std::cout << "│" << std::setw(10)  << "nickname" << "│" << std::endl;
//         std::cout << "|**********|**********|**********|**********|" << std::endl;

//     }

// }

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
        else
			std::cout << "Invalid choice!" << std::endl;
    }
    return 0;
}