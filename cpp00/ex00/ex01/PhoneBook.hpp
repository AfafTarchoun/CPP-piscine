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
#include <iomanip> 
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    int index;
    int count = 0;
    Contact contact[8];
    public:
        PhoneBook (void);
        ~PhoneBook (void);
        int counting() const
        {
            return this->count;
        }
        Contact getcount(int index) const
        {
            return this->contact[index];
        }
        void setcont(Contact contact)
        {
            this->contact[this->index] = contact;
            this->index = (this->index + 1) % 8;
            this->count++;
        }
};

#endif