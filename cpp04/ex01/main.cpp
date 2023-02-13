/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:39:48 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:40:26 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // Cat *mchicha = new Cat();
    // Cat *mech = new Cat(*mchicha);
    
    // Dog basic;
    // {
    //     Dog tmp = basic;
    // }
    
    // delete mech;
    // delete mchicha;
    delete j;
    delete i;
    return 0;
}
