/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:51:26 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:16:29 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <cstring>

class Contact
{
    public:
    //getters
        std::string get_first() {return this->first_name;}
        std::string get_last() {return this->last_name;}
        std::string get_nickname() {return this->nickname;}
        std::string get_nb() {return this->phone_nb;}
        std::string get_dark() {return this->dark_scrt;}
    //setters
        void set_first(std::string name) {this->first_name=name;}
        void set_last(std::string name) {this->last_name=name;}
        void set_nickname(std::string name) {this->nickname=name;}
        void set_nb(std::string nb) {this->phone_nb=nb;}
        void set_dark(std::string scrt) {this->dark_scrt=scrt;}

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_nb;
        std::string dark_scrt;
};
#endif