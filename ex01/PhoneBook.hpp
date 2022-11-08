/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:12 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK
#include <iostream>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
    Contact contact[8];
    public:
        int index;
        PhoneBook (void);
        ~PhoneBook (void);

};

#endif