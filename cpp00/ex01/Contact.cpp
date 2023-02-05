/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:31:46 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/05 00:36:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//getters
std::string Contact::get_first() {return first_name;}
std::string Contact::get_last() {return last_name;}
std::string Contact::get_nickname() {return nickname;}
std::string Contact::get_nb() {return phone_nb;}
std::string Contact::get_dark() {return dark_scrt;}

//setters
void Contact::set_first(std::string& name) {first_name = name;}
void Contact::set_last(std::string& name) {last_name = name;}
void Contact::set_nickname(std::string& name) {nickname = name;}
void Contact::set_nb(std::string& nb) {phone_nb = nb;}
void Contact::set_dark(std::string& scrt) {dark_scrt = scrt;}
