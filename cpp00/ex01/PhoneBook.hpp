/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:12 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/04 21:19:50 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     current_index;
    public:
        PhoneBook() : current_index(0) {}
        void setcont(Contact contact);
        void search_contact(int index);
        void display_contacts();
};

#endif