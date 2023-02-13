/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:38:44 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:38:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
int main()
{
    Cat *a = new Cat();
    Cat *p = new Cat(*a);
    Animal *ss = new Cat(); // it cannot work since it an abstract class
    p->getIdeas();
    // delete j;//should not create a leak
    delete p;
    delete a;
    
}