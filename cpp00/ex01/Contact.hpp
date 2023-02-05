/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:26 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/05 00:36:05 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <cstring>

class Contact
{
    public:
        std::string get_first();
        std::string get_last();
        std::string get_nickname();
        std::string get_nb();
        std::string get_dark();

        void set_first(std::string& name);
        void set_last(std::string& name);
        void set_nickname(std::string& name);
        void set_nb(std::string& nb);
        void set_dark(std::string& scrt);

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_nb;
        std::string dark_scrt;
};

#endif