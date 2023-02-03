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

class PhoneBook
{
    private:
        Contact contacts[8];
        int     current_index = 0;
    public:
        void setcont(Contact contact);
        void search_contact(int index);
        void display_contacts();
};

#endif