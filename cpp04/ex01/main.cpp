/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:39:48 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:39:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


int main()
{

    Cat *a = new Cat();
    Cat *p = new Cat(*a);
    Dog *x = new Dog();
    Dog *y = new Dog(*x);
    // Dog basic;
    // {
    //     Dog tmp = basic;
    // }
    
    p->getIdeas();
    std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
    y->getIdeas();
    delete p;
    delete a;
    // delete x;
    // delete y;
    
}
