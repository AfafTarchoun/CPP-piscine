/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:38:44 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/15 20:59:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
int main()
{
    Cat *a = new Cat();
    Cat *p = new Cat(*a);
    // Animal ss;// it won't work it's an abstract class
    p->getIdeas();
    delete p;
    delete a;
}
