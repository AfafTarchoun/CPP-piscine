/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "form.hpp"

int main()
{
    try
    {
        Form f("form", 150, 150);
        Bureaucrat b(11, "bureaucrat");
        std::cout << b;
        b.signForm(f);
        f.beSigned(b);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}