/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:48:15 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:32 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP
#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base* generate();
void  identify(Base* p);
void  identify(Base& p);
#endif