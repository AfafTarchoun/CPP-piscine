/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:59 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 16:47:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
    Base* p = generate();
    identify(p);
    Base& r = *p;
    identify(r);
    delete p;
    return 0;
}
