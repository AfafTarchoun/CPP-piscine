/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:19 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:42:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX02_HPP
#define EX02_HPP

#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif