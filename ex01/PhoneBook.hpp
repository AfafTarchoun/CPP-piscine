/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:12 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/09 17:35:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK
#include <iostream>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    int index;
    Contact contact[8];
    public:

        PhoneBook (void);
        ~PhoneBook (void);
    void add_contact(Contact contact)
    {
        std::cout<<"why seg?"<<std::endl;
        this->contact[this->index] = contact;
        // _count = (_count < 8) ? _count + 1 : _count;
        this->index = (this->index + 1) % 8;
    }

};

#endif