/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:26 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/08 17:24:50 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT
#include <iostream>
#include <cstring>

class Contact
{
    public:
        Contact();
        ~Contact();
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_nb;
        std::string darkest_secret;
};


#endif