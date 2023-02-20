/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:48:13 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 20:08:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Identify.hpp"

Base* generate()
{
    srand(time(0));
    int r = rand() % 3;
    if (r == 0)
    {
        return new A;
    }
    else if (r == 1)
    {
        return new B;
    }
    else
    {
        return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != nullptr)
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != nullptr)
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != nullptr)
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } 
    catch (const std::bad_cast&) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::bad_cast&) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::bad_cast&) {}
}