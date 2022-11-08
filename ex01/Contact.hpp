/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:26 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/08 17:53:53 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT
#include <iostream>
#include <cstring>

class Contact
{
    public:
    //getters
        std::string get_first() const;
        std::string get_last() const;
        std::string get_nickname() const;
        std::string get_nb() const;
        std::string get_dark() const;
    //setters
        void set_first(std::string name);
        void set_last(std::string name);
        void set_nickname(std::string name);
        void set_nb(std::string nb);
        void set_dark(std::string scrt);
    
    Contact();
    ~Contact();
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_nb;
        std::string dark_scrt;
};


#endif