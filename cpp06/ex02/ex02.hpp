/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:48:15 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 03:49:41 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    int r = rand() % 3;
    if (r == 0) {
        return new A;
    } else if (r == 1) {
        return new B;
    } else {
        return new C;
    }
}